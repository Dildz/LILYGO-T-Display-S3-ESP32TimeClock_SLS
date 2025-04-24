/*************************************************************
******************* INCLUDES & DEFINITIONS *******************
**************************************************************/

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <WiFiManager.h>
#include <EEPROM.h>
#include <ESP32Time.h>

#include "driver/temp_sensor.h"
#include "LV_Helper.h"
#include "ui.h"
#include "pins.h"

// Built-in buttons
#define bootBTN  PIN_BUTTON_1
#define keyBTN   PIN_BUTTON_2

// EEPROM settings
#define EEPROM_SIZE sizeof(ConfigData)
#define EEPROM_ADDR 0

// Configuration structure for EEPROM
typedef struct {
  long gmtOffset;
  byte dstOffset;
  bool EEPROMinitialized; // flag to check if EEPROM has initialized
} ConfigData;
ConfigData config;

// Initialize ESP32Time
ESP32Time rtc(0); // initialize with 0 offset, it will get updated later

// Time storage
struct tm lastLocalTime;
unsigned long lastTimeUpdate = 0;

// NTP settings
const char* ntpServer = "pool.ntp.org";

// Initialize TFT display
TFT_eSPI lcd = TFT_eSPI();

// Brightness control variables
byte currentBrightness = 160;   // start at 160
const byte brightnessStep = 40; // step size
const byte minBrightness = 80;  // minimum brightness
const byte maxBrightness = 240; // maximum brightness

// Button debounce delay
const byte debounceDelay = 20;

// IP address as a string
String ipString = "";

// NTP sync variables
unsigned long lastNTPSync = 0;
const unsigned long ntpSyncInterval = 3600000; // 1 hour

// NTP sync states
enum SyncState {
  SYNC_FAILED,
  SYNC_SUCCESS
};
SyncState rtcSyncState = SYNC_FAILED; // start in failed state until first successful sync
String lastResponseTime = "NEVER";    // store the last response string

// Frame rate control
const unsigned long frameInterval = 33; // ~30 FPS (1000ms/30 = 33.33ms per frame)
unsigned long lastFrameTime = 0;


/*************************************************************
********************** HELPER FUNCTIONS **********************
**************************************************************/

// Function to validate timezone inputs
bool validateTZData(const char* gmtStr, const char* dstStr) {
  long gmt = atoi(gmtStr);
  if (gmt < -12 || gmt > 14) return false;
  
  byte dst = atoi(dstStr);
  if (dst != 0 && dst != 1) return false;
  
  return true;
}

// Function to check for a configuration portal trigger (both buttons held for 5 seconds)
bool configPortalTrigger() {
  static unsigned long pressStartTime = 0;
  static bool bothPressed = false;
  
  bool bootBtnPressed = (digitalRead(bootBTN) == LOW);
  bool keyBtnPressed = (digitalRead(keyBTN) == LOW);
  
  if (bootBtnPressed && keyBtnPressed) {
    if (!bothPressed) {
      // First detection of both buttons pressed
      bothPressed = true;
      pressStartTime = millis();
    }
    else if (millis() - pressStartTime >= 5000) {
      // Both buttons held for 5 seconds
      bothPressed = false;
      return true;
    }
  }
  else {
    bothPressed = false;
  }
  return false;
}

// Function to sync RTC with NTP server
bool syncWithNTP() {
  // Get time in UTC without applying offset
  configTime(0, 0, ntpServer); // set offset to 0
  
  if (!getLocalTime(&lastLocalTime, 10000)) {
    return false;
  }
  
  // Update ESP32Time with the GMT offset
  rtc.setTimeStruct(lastLocalTime);
  rtc.offset = config.gmtOffset * 3600; // set the GMT offset
  
  // Get the offset local time
  lastLocalTime = rtc.getTimeStruct();
  
  char syncTimeStr[9];
  snprintf(syncTimeStr, sizeof(syncTimeStr), "%02d:%02d:%02d",
           lastLocalTime.tm_hour, lastLocalTime.tm_min, lastLocalTime.tm_sec);
  lastResponseTime = syncTimeStr;
  lastTimeUpdate = millis();

  return true;
}

// Function to update local time between syncs
void updateLocalTime() {
  static unsigned long lastUpdateMillis = 0;
  unsigned long currentMillis = millis();
  unsigned long elapsedSeconds = (currentMillis - lastUpdateMillis) / 1000;
  
  if (elapsedSeconds >= 1) {
    // Get current ESP32Time
    lastLocalTime = rtc.getTimeStruct();
    lastUpdateMillis = currentMillis;
  }
}

// Function to save extra Wi-Fi Manager configs to EEPROM
void saveConfig() {
  EEPROM.put(EEPROM_ADDR, config);
  EEPROM.commit();
}

// Function to initialize EEPROM
void initEEPROM() {
  EEPROM.begin(EEPROM_SIZE);
  
  // Read config from EEPROM
  EEPROM.get(EEPROM_ADDR, config);
  
  // If EEPROM is empty or contains invalid values, initialize with defaults
  if (!config.EEPROMinitialized || config.gmtOffset < -12 || config.gmtOffset > 14 || 
      (config.dstOffset != 0 && config.dstOffset != 1)) {
    config.gmtOffset = 0; // default to UTC
    config.dstOffset = 0; // default to no DST
    config.EEPROMinitialized = true;
    saveConfig();
  }
}

// Function to update time with flashing colon
void updateTime() {
  static unsigned long lastUpdate = 0;
  static bool colonVisible = true;
  const unsigned long updateInterval = 500; // colon blink period
  
  if (millis() - lastUpdate >= updateInterval) {
    if (rtc.getEpoch() > 1609459200) { // check if time is valid (after 1/1/2021)
      // Update local time between syncs
      if (millis() - lastTimeUpdate >= 1000) {
        updateLocalTime();

        // Update display
        char hourStr[3], minStr[3], secStr[3];
        snprintf(hourStr, sizeof(hourStr), "%02d", lastLocalTime.tm_hour);
        snprintf(minStr, sizeof(minStr), "%02d", lastLocalTime.tm_min);
        snprintf(secStr, sizeof(secStr), "%02d", lastLocalTime.tm_sec);
        
        lv_label_set_text(ui_timeH, hourStr);
        lv_label_set_text(ui_timeM, minStr);
        lv_label_set_text(ui_timeS, secStr);

        lastTimeUpdate = millis();
      }
      
      // Toggle colon visibility
      colonVisible = !colonVisible;
      lv_obj_set_style_opa(ui_timeColon, colonVisible ? LV_OPA_100 : LV_OPA_0, LV_PART_MAIN);
    }
    else {
      // If time isn't valid, show default values
      lv_label_set_text(ui_timeH, "00");
      lv_label_set_text(ui_timeM, "00");
      lv_label_set_text(ui_timeS, "00");
      lv_obj_set_style_opa(ui_timeColon, LV_OPA_100, LV_PART_MAIN);
    }
    lastUpdate = millis();
  }
}

// Function to update date labels
void updateDate() {
  static unsigned long lastDateUpdate = 0;
  
  if (millis() - lastDateUpdate >= 1000) {
    const char* daysOfWeek[] = {"SUN.", "MON.", "TUE.", "WED.", "THU.", "FRI.", "SAT."};
    lv_label_set_text(ui_day, daysOfWeek[lastLocalTime.tm_wday]);
    
    char dateStr[11];
    snprintf(dateStr, sizeof(dateStr), "%02d-%02d-%04d",
             lastLocalTime.tm_mday, lastLocalTime.tm_mon + 1, lastLocalTime.tm_year + 1900);
    lv_label_set_text(ui_date, dateStr);
    
    lastDateUpdate = millis();
  }
}

// Function to update CPU temperature
void updateCPUTemp() {
  static unsigned long lastTempUpdate = 0;
  const unsigned long tempUpdateInterval = 1000; // update every second
  
  if (millis() - lastTempUpdate >= tempUpdateInterval) {
      float temp = 0;
      temp_sensor_read_celsius(&temp);
      
      // Format as "XX °C"
      char tempStr[10];
      snprintf(tempStr, sizeof(tempStr), "%02d C", (int)round(temp));
      lv_label_set_text(ui_CPUtemp, tempStr);
      
      lastTempUpdate = millis();
  }
}

// Function to check and maintain Wi-Fi connection
void checkWiFiStatus() {
  static unsigned long lastWiFiUpdate = 0;
  const unsigned long wifiUpdateInterval = 1000; // update every second
  
  if (millis() - lastWiFiUpdate >= wifiUpdateInterval) {
    if (WiFi.status() == WL_CONNECTED) {
      // Get RSSI value
      int rssi = WiFi.RSSI();
      
      // Update RSSI label with dBm value
      char rssiStr[10];
      snprintf(rssiStr, sizeof(rssiStr), "%d dBm", rssi);
      lv_label_set_text(ui_RSSI, rssiStr);
      
      // Determine WiFi icon color based on signal strength
      lv_color_t wifiColor;
      if (rssi >= -50) {
        wifiColor = lv_color_hex(0x00FF00); // Green - Excellent (>-50dBm)
      } 
      else if (rssi >= -60) {
        wifiColor = lv_color_hex(0x7CFC00); // Green-Yellow - Very good (-50 to -60dBm)
      }
      else if (rssi >= -70) {
        wifiColor = lv_color_hex(0xFFFF00); // Yellow - Okay (-60 to -70dBm)
      }
      else if (rssi >= -80) {
        wifiColor = lv_color_hex(0xFFA500); // Orange - Weak (-70 to -80dBm)
      }
      else {
        wifiColor = lv_color_hex(0xFF0000); // Red - Very weak (<-80dBm)
      }
      
      // Set the icon color
      lv_obj_set_style_img_recolor(ui_wifiImage, wifiColor, LV_PART_MAIN);
      lv_obj_set_style_img_recolor_opa(ui_wifiImage, LV_OPA_COVER, LV_PART_MAIN);

      // Only attempt NTP sync if WiFi is connected
      if (millis() - lastNTPSync >= ntpSyncInterval) {
        if (syncWithNTP()) {
          lastNTPSync = millis();
          rtcSyncState = SYNC_SUCCESS;
          
          // Update UI after successful sync
          lv_label_set_text(ui_lastSyncTime, lastResponseTime.c_str());
          lv_obj_clear_flag(ui_rtcSynced, LV_OBJ_FLAG_HIDDEN);
          lv_obj_add_flag(ui_rtcFailed, LV_OBJ_FLAG_HIDDEN);
        }
        else {
          rtcSyncState = SYNC_FAILED;
          lv_obj_add_flag(ui_rtcSynced, LV_OBJ_FLAG_HIDDEN);
          lv_obj_clear_flag(ui_rtcFailed, LV_OBJ_FLAG_HIDDEN);
        }
      }
    } 
    else {
      // WiFi disconnected - set icon to black and show "Disconnected"
      lv_obj_set_style_img_recolor(ui_wifiImage, lv_color_hex(0x000000), LV_PART_MAIN);
      lv_obj_set_style_img_recolor_opa(ui_wifiImage, LV_OPA_COVER, LV_PART_MAIN);
      lv_label_set_text(ui_RSSI, "Disconnected");
      
      // Attempt to reconnect periodically
      static unsigned long lastReconnectAttempt = 0;
      if (millis() - lastReconnectAttempt >= 10000) { // Try every 10 seconds
        lastReconnectAttempt = millis();
        WiFi.reconnect();
      }
    }
    lastWiFiUpdate = millis();
  }
}

// Function to check for button presses
void checkButtons() {
  static bool lastBootBtnState = HIGH;
  static bool lastKeyBtnState = HIGH;
  static unsigned long lastDebounceTime = 0;
  
  bool bootBtnState = digitalRead(bootBTN);
  bool keyBtnState = digitalRead(keyBTN);

  // Debounce check
  if (millis() - lastDebounceTime > debounceDelay) {
    // Boot button pressed (falling edge)
    if (bootBtnState == LOW && lastBootBtnState == HIGH) {
      if (currentBrightness > minBrightness) { // only decrease if not at minimum
        currentBrightness -= brightnessStep;
      }
      analogWrite(PIN_LCD_BL, currentBrightness);
    }

    // Key button pressed (falling edge)
    if (keyBtnState == LOW && lastKeyBtnState == HIGH) {
      if (currentBrightness < maxBrightness) { // only increase if not at maximum
        currentBrightness += brightnessStep;
      }
      analogWrite(PIN_LCD_BL, currentBrightness);
    }

    lastDebounceTime = millis();
  }

  // Update last button states
  lastBootBtnState = bootBtnState;
  lastKeyBtnState = keyBtnState;

  // Update brightness bar value
  lv_bar_set_value(ui_brightnessBar, currentBrightness, LV_ANIM_ON);
}

// Function to start WiFiManager configuration portal
void startConfigPortal() {
  // Clear the screen and display instructions
  lcd.fillScreen(TFT_BLACK);
  lcd.setTextColor(0x7BCF, TFT_BLACK); // converted from #787878
  lcd.setCursor(0, 0);
  
  lcd.println("Entered Wi-Fi Configuration Mode\n\n");
  lcd.println("A Wi-Fi network has been created:\n");
  lcd.println("SSID:     T-Display-S3\n");
  lcd.println("Password: 123456789\n\n");
  lcd.println("Connect and navigate to: 192.168.4.1\n");
  lcd.println("in a browser to setup your Wi-Fi.\n\n");

  // Create WiFiManager instance with custom parameters
  WiFiManager wifiManager;

  // Create buffers initialized with "0"
  char gmtValue[4] = "0";
  char dstValue[2] = "0";

  // Only overwrite if we have valid values
  if (config.EEPROMinitialized) {
    snprintf(gmtValue, sizeof(gmtValue), "%ld", config.gmtOffset);
    snprintf(dstValue, sizeof(dstValue), "%d", config.dstOffset);
  }

  // Add custom parameters for GMT and DST offsets
  WiFiManagerParameter custom_gmt("gmt", "GMT Offset (-12 to +14)", gmtValue, 3);
  WiFiManagerParameter custom_dst("dst", "DST Offset (0 or 1)", dstValue, 1);
  wifiManager.addParameter(&custom_gmt);
  wifiManager.addParameter(&custom_dst);
  
  wifiManager.setConnectTimeout(30);
  wifiManager.setConfigPortalTimeout(0);
  
  if (!wifiManager.startConfigPortal("T-Display-S3", "123456789")) {
    lcd.println("Failed to connect, rebooting...\n");
    delay(3000);
  }
  else {
    // Validate and save new parameters
    if (validateTZData(custom_gmt.getValue(), custom_dst.getValue())) {
      config.gmtOffset = atoi(custom_gmt.getValue());
      config.dstOffset = atoi(custom_dst.getValue());
      saveConfig();
    }
    
    lcd.println("Configuration saved, rebooting...");
    delay(2000);
    ESP.restart();
  }
}


/*************************************************************
*********************** MAIN FUNCTIONS ***********************
**************************************************************/

// SETUP
void setup() {
  // Initialize hardware
  pinMode(bootBTN, INPUT_PULLUP);   // BOOT button
  pinMode(keyBTN, INPUT_PULLUP);    // KEY button
  pinMode(PIN_POWER_ON, OUTPUT);    // display power pin
  digitalWrite(PIN_POWER_ON, HIGH); // turn on display

  // Initialize EEPROM
  initEEPROM();

  // Set the timezone offset
  rtc.offset = config.gmtOffset * 3600;
  
  // Initialize temperature sensor
  temp_sensor_config_t temp_sensor = TSENS_CONFIG_DEFAULT();
  temp_sensor.dac_offset = TSENS_DAC_L2; // L4(-40°C ~ 20°C), L2(-10°C ~ 80°C), L1(20°C ~ 100°C), L0(50°C ~ 125°C)
  temp_sensor_set_config(temp_sensor);
  temp_sensor_start();

  // Initialize display
  lcd.init();
  lcd.setRotation(1);                         // landscape
  ledcSetup(0, 5000, 8);                      // 5kHz PWM, 8-bit resolution
  analogWrite(PIN_LCD_BL, LOW);               // start with backlight OFF
  lcd.fillScreen(TFT_BLACK);                  // clear screen
  lcd.setTextColor(0x7BCF, TFT_BLACK);        // converted from #787878
  analogWrite(PIN_LCD_BL, currentBrightness); // display brightness (160/255)

  // Display initial message
  lcd.println("\nConnecting to Wi-Fi - please wait...(up to 30s)\n");

  // Initialize WiFiManager with parameters
  WiFiManager wifiManager;

  char gmtValue[6] = "0";  // Default to "0" if EEPROM not initialized
  char dstValue[2] = "0";  // Default to "0" if EEPROM not initialized

  if (config.EEPROMinitialized) {
      snprintf(gmtValue, sizeof(gmtValue), "%ld", config.gmtOffset);
      snprintf(dstValue, sizeof(dstValue), "%d", config.dstOffset);
  }

  WiFiManagerParameter custom_gmt("gmt", "GMT Offset (-12 to +14)", gmtValue, 3);
  WiFiManagerParameter custom_dst("dst", "DST Offset (0 or 1)", dstValue, 1);
  wifiManager.addParameter(&custom_gmt);
  wifiManager.addParameter(&custom_dst);

  wifiManager.setHostname("LILYGO-T-Display-S3");
  wifiManager.setConnectTimeout(10);
  wifiManager.setConnectRetries(3);
  wifiManager.setConfigPortalTimeout(0);
  
  // Callback for config portal
  wifiManager.setAPCallback([](WiFiManager *wm) {
    lcd.fillScreen(TFT_BLACK);
    lcd.setCursor(0, 0);
    lcd.println("AP unreachable or not yet configured.\n\n");
    lcd.println("A Wi-Fi network has been created:\n");
    lcd.println("SSID:     T-Display-S3\n");
    lcd.println("Password: 123456789\n\n");
    lcd.println("Connect and navigate to: 192.168.4.1\n");
    lcd.println("in a browser to setup your Wi-Fi.\n\n");
  });

  // Callback for a saved config
  wifiManager.setSaveConfigCallback([]() {
    lcd.println("Configuration saved, rebooting...");
    delay(2000);
    ESP.restart();
  });

  // This will block until connected to saved network or after config
  wifiManager.autoConnect("T-Display-S3", "123456789");

  // After connection, check if we need to update the offsets
  if (validateTZData(custom_gmt.getValue(), custom_dst.getValue())) {
    long newGmt = atoi(custom_gmt.getValue());
    byte newDst = atoi(custom_dst.getValue());
    
    if (newGmt != config.gmtOffset || newDst != config.dstOffset) {
      config.gmtOffset = newGmt;
      config.dstOffset = newDst;
      saveConfig();
    }
  }

  // Wi-Fi connected :)
  lcd.println("WiFi Connected! :)\n");
  lcd.print("SSID: ");
  lcd.println(WiFi.SSID());
  lcd.print("IP: ");
  lcd.println(WiFi.localIP());
  ipString = (WiFi.localIP().toString()); // update IP address string
  delay(1000);

  // Attempt to sync RTC with NTP server
  lcd.println("Attempting initial NTP sync...\n");

  bool syncSuccess = false;
  byte retryCount = 0;
  const byte maxRetries = 3;

  while (!syncSuccess && retryCount < maxRetries) {
    lcd.printf("Attempt %d of %d\n", retryCount + 1, maxRetries);
    syncSuccess = syncWithNTP();
    
    if (syncSuccess) {
      rtcSyncState = SYNC_SUCCESS;
      lcd.println("NTP sync successful!\n");
      lastNTPSync = millis();
    }
    else {
      // Set a reasonable default time if sync fails
      rtc.setTime(0, 0, 0, 1, 1, 2023); // Jan 1, 2023
      retryCount++;
      delay(5000);
    }
  }

  if (!syncSuccess) {
    rtcSyncState = SYNC_FAILED;
    lastResponseTime = "FAILED";
    lcd.println("Failed to sync with NTP server\n");
  }
  delay(1000);

  lcd.println("Starting main display...");
  delay(2000);

  // Initialize lvgl UI
  lv_helper();
  ui_init();

  // Update GMT label
  char gmtLabel[4];
  snprintf(gmtLabel, sizeof(gmtLabel), "%+ld", config.gmtOffset);
  lv_label_set_text(ui_GMT, gmtLabel);
  
  // Update DST label
  const char* dstLabel = (config.dstOffset == 1) ? "ON" : "OFF";
  lv_label_set_text(ui_DST, dstLabel);

  // Update IP address label
  lv_label_set_text(ui_IPadd, ipString.c_str());

  // Update sync status labels
  if (rtcSyncState == SYNC_SUCCESS) {
    lv_obj_clear_flag(ui_rtcSynced, LV_OBJ_FLAG_HIDDEN); // show SYNCED
    lv_obj_add_flag(ui_rtcFailed, LV_OBJ_FLAG_HIDDEN);   // hide FAILED
  }
  else {
    lv_obj_add_flag(ui_rtcSynced, LV_OBJ_FLAG_HIDDEN);   // hide SYNCED
    lv_obj_clear_flag(ui_rtcFailed, LV_OBJ_FLAG_HIDDEN); // show FAILED
  }
  lv_label_set_text(ui_lastSyncTime, lastResponseTime.c_str());

  // Update FPS label (fixed value since we limit the FPS to 30 in main loop)
  lv_label_set_text(ui_FPS, "30");
}

// MAIN LOOP
void loop() {
  // Frame rate limiter
  unsigned long currentTime = millis();
  unsigned long elapsed = currentTime - lastFrameTime;
  
  // Calculate how much time we need to delay to maintain 30 FPS
  if (elapsed < frameInterval) {
    unsigned long waitTime = frameInterval - elapsed;
    delay(waitTime);
  }
  lastFrameTime = millis();

  // Check for simultaneous button press (config portal trigger)
  if (configPortalTrigger()) {
    startConfigPortal();
  }
  
  lv_task_handler();

  checkButtons();
  checkWiFiStatus();
  
  updateTime();
  updateDate();
  updateCPUTemp();

  lv_refr_now(NULL);
}

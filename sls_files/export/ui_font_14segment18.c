/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --font C:/Users/Dildz/Documents/SquareLine/Projects/T-Display-S3-RTC/assets/DSEG14Classic-Regular.ttf -o C:/Users/Dildz/Documents/SquareLine/Projects/T-Display-S3-RTC/assets\ui_font_14segment18.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_14SEGMENT18
#define UI_FONT_14SEGMENT18 1
#endif

#if UI_FONT_14SEGMENT18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x0,

    /* U+0022 "\"" */
    0xc1, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xc0,

    /* U+0024 "$" */
    0x7f, 0xec, 0x60, 0xc6, 0xc, 0x60, 0xc6, 0xc,
    0x60, 0xc6, 0xc, 0x60, 0xc4, 0x7, 0xfe, 0x6,
    0x30, 0x63, 0x6, 0x30, 0x63, 0x6, 0x30, 0x63,
    0x6, 0x37, 0xfe,

    /* U+0025 "%" */
    0xc0, 0x1c, 0x13, 0x82, 0x78, 0xcf, 0x19, 0xa2,
    0x34, 0x84, 0x0, 0x7b, 0xc0, 0xc, 0x45, 0x88,
    0xb3, 0x1e, 0x41, 0xc8, 0x38, 0x3,

    /* U+0026 "&" */
    0xff, 0x80, 0x4, 0x11, 0x4, 0x63, 0x8, 0x82,
    0x20, 0x0, 0x0, 0x0, 0x10, 0xc, 0x8b, 0x22,
    0xd8, 0xf4, 0x1d, 0x7, 0x0, 0xff, 0xe0,

    /* U+0027 "'" */
    0xff, 0xf0,

    /* U+0028 "(" */
    0x2f, 0xe9, 0x0, 0x93, 0x76, 0x40,

    /* U+0029 ")" */
    0x93, 0x36, 0x40, 0x2d, 0xe9, 0x0,

    /* U+002A "*" */
    0x4c, 0x9b, 0x66, 0xf8, 0xfc, 0x3e, 0x7, 0x80,
    0x83, 0xff, 0x1e, 0x7, 0x83, 0xf0, 0xbc, 0x6d,
    0x93, 0x20,

    /* U+002B "+" */
    0xc, 0x3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc3, 0xff, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0,

    /* U+002C "," */
    0x2d, 0xe9, 0x0,

    /* U+002D "-" */
    0xf7, 0x80,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x2, 0x4, 0x18, 0x60, 0xc1, 0x0, 0x0, 0x20,
    0xc1, 0x86, 0x8, 0x10, 0x0,

    /* U+0030 "0" */
    0x7f, 0xf8, 0x1f, 0x3, 0xe0, 0xfc, 0x1f, 0x82,
    0xf0, 0x5e, 0x3, 0x80, 0x30, 0x7, 0x1, 0xe8,
    0x3d, 0x7, 0xe0, 0xfc, 0x1f, 0x3, 0xe0, 0x7f,
    0xf8,

    /* U+0031 "1" */
    0x3f, 0xff, 0x5f, 0xff, 0x40,

    /* U+0032 "2" */
    0x7f, 0xe0, 0xc, 0x1, 0x80, 0x30, 0x6, 0x0,
    0xc0, 0x18, 0x3, 0x0, 0x6f, 0x7b, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x1f,
    0xf8,

    /* U+0033 "3" */
    0x7f, 0xe0, 0xc, 0x1, 0x80, 0x30, 0x6, 0x0,
    0xc0, 0x18, 0x3, 0x0, 0x7f, 0xf8, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x18, 0x3, 0x0, 0x6f,
    0xf8,

    /* U+0034 "4" */
    0x0, 0x18, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x7b, 0xc0, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x18, 0x3,

    /* U+0035 "5" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0xf, 0x78, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x18, 0x3, 0x0, 0x6f,
    0xf8,

    /* U+0036 "6" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0xf, 0x7b, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xc0, 0x7f,
    0xf8,

    /* U+0037 "7" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1c, 0x1, 0x0, 0x20, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x18, 0x3,

    /* U+0038 "8" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x6f, 0x7b, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xc0, 0x7f,
    0xf8,

    /* U+0039 "9" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x6f, 0x78, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x18, 0x3, 0x0, 0x6f,
    0xf8,

    /* U+003A ":" */
    0xc0, 0x0, 0xc0,

    /* U+003C "<" */
    0x1, 0x0, 0x80, 0xc0, 0xc0, 0x60, 0x20, 0x0,
    0x0, 0x10, 0x18, 0xc, 0xc, 0x4, 0x2, 0x0,
    0x1, 0xff,

    /* U+003D "=" */
    0xf7, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x80,

    /* U+003E ">" */
    0x40, 0x20, 0x18, 0x6, 0x3, 0x0, 0x80, 0x0,
    0x0, 0x4, 0x3, 0x1, 0x80, 0x60, 0x10, 0x8,
    0x1, 0xff,

    /* U+003F "?" */
    0x7f, 0xfc, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c,
    0x3, 0xc0, 0x3c, 0x3, 0x3, 0xe0, 0x60, 0x6,
    0x0, 0x60, 0x6, 0x0, 0x60, 0x6, 0x0, 0x60,

    /* U+0040 "@" */
    0x7f, 0xfc, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x30, 0x3e, 0xc6,
    0x3c, 0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c, 0x63,
    0xc6, 0x3f, 0xfe,

    /* U+0041 "A" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x7b, 0xd8, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3,

    /* U+0042 "B" */
    0xff, 0xe1, 0x8c, 0x31, 0x86, 0x30, 0xc6, 0x18,
    0xc3, 0x18, 0x63, 0x8, 0x60, 0xf8, 0x31, 0x86,
    0x30, 0xc6, 0x18, 0xc3, 0x18, 0x63, 0xc, 0x7f,
    0xf8,

    /* U+0043 "C" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0x80, 0x10, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x1f,
    0xf8,

    /* U+0044 "D" */
    0xff, 0xe0, 0xc, 0x31, 0x86, 0x30, 0xc6, 0x18,
    0xc3, 0x18, 0x63, 0x0, 0x20, 0x4, 0x31, 0x86,
    0x30, 0xc6, 0x18, 0xc3, 0x18, 0x63, 0x0, 0x7f,
    0xf8,

    /* U+0045 "E" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0xf, 0xff, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x1f,
    0xf8,

    /* U+0046 "F" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0x7f, 0xf8, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0,

    /* U+0047 "G" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x0, 0x7b, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xc0, 0x7f,
    0xf8,

    /* U+0048 "H" */
    0x0, 0x18, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x7b, 0xd8, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3,

    /* U+0049 "I" */
    0xff, 0xc0, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0x0, 0x0, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0x0, 0x3f, 0xf0,

    /* U+004A "J" */
    0x0, 0x20, 0xc, 0x1, 0x80, 0x30, 0x6, 0x0,
    0xc0, 0x18, 0x1, 0x80, 0x38, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xff, 0xc0,

    /* U+004B "K" */
    0xc0, 0x60, 0x70, 0x38, 0x3c, 0x1e, 0xb, 0x5,
    0x80, 0x7c, 0x60, 0x30, 0x58, 0x2c, 0x1e, 0x7,
    0x3, 0x80,

    /* U+004C "L" */
    0x80, 0x18, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x4, 0x0, 0x80, 0x18, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xff, 0xc0,

    /* U+004D "M" */
    0xc0, 0x7c, 0x1f, 0x83, 0xf8, 0x7d, 0x9f, 0xb2,
    0xf2, 0x5c, 0x1, 0x80, 0x38, 0xcf, 0x19, 0xe3,
    0x3c, 0x67, 0x8c, 0xf1, 0x9e, 0x3,

    /* U+004E "N" */
    0xc0, 0x7c, 0xf, 0xc1, 0xf8, 0x3d, 0x7, 0xa0,
    0xf4, 0x1c, 0x1, 0x80, 0x38, 0x4f, 0x5, 0xe0,
    0xbc, 0x1f, 0x83, 0xf0, 0x3e, 0x3,

    /* U+004F "O" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x80, 0x30, 0x7, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xc0, 0x7f,
    0xf8,

    /* U+0050 "P" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x7b, 0xd8, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0,

    /* U+0051 "Q" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x80, 0x30, 0x7, 0x1, 0xe0,
    0xbc, 0x17, 0x83, 0xf0, 0x7e, 0x7, 0xc0, 0xff,
    0xf8,

    /* U+0052 "R" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x7b, 0xd8, 0x3, 0x4, 0x60,
    0x8c, 0x19, 0x83, 0x30, 0x26, 0x4, 0x80, 0x0,

    /* U+0053 "S" */
    0x7f, 0xdc, 0x3, 0x80, 0x78, 0xf, 0x1, 0xa0,
    0x34, 0x6, 0x80, 0xc0, 0xf, 0x78, 0x1, 0x80,
    0xb0, 0x16, 0x2, 0xc0, 0x78, 0x7, 0x0, 0xef,
    0xf8,

    /* U+0054 "T" */
    0xff, 0xc3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x0, 0x0, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0,

    /* U+0055 "U" */
    0x80, 0x38, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1c, 0x1, 0x80, 0x38, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xff, 0xc0,

    /* U+0056 "V" */
    0xc0, 0x60, 0x70, 0x38, 0x3c, 0x1e, 0xb, 0x5,
    0x0, 0x80, 0x64, 0x36, 0x1b, 0xf, 0x7, 0x3,
    0x81, 0x80,

    /* U+0057 "W" */
    0xc0, 0x78, 0xcf, 0x19, 0xe3, 0x3c, 0x67, 0x8c,
    0xf1, 0x9c, 0x1, 0x80, 0x39, 0x2f, 0x65, 0xec,
    0xff, 0xf, 0xc1, 0xf8, 0x3e, 0x3,

    /* U+0058 "X" */
    0x83, 0x7, 0x1a, 0x24, 0x40, 0x0, 0x0, 0x0,
    0x89, 0x16, 0x38, 0x30, 0x40,

    /* U+0059 "Y" */
    0x83, 0x7, 0xb, 0x36, 0x44, 0x80, 0x0, 0x18,
    0x30, 0x60, 0xc1, 0x83, 0x0,

    /* U+005A "Z" */
    0xff, 0x80, 0x80, 0x40, 0x60, 0x30, 0x30, 0x18,
    0x8, 0x0, 0x0, 0x4, 0x6, 0x3, 0x3, 0x1,
    0x80, 0x80, 0x40, 0x7f, 0xc0,

    /* U+005C "\\" */
    0x81, 0x3, 0x3, 0x6, 0x4, 0x0, 0x0, 0x8,
    0x18, 0x30, 0x30, 0x20, 0x40,

    /* U+005E "^" */
    0xc7, 0x39, 0xed, 0xef, 0x30,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0060 "`" */
    0x93, 0x36, 0x40,

    /* U+0061 "a" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x7b, 0xd8, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3,

    /* U+0062 "b" */
    0xff, 0xe1, 0x8c, 0x31, 0x86, 0x30, 0xc6, 0x18,
    0xc3, 0x18, 0x63, 0x8, 0x60, 0xf8, 0x31, 0x86,
    0x30, 0xc6, 0x18, 0xc3, 0x18, 0x63, 0xc, 0x7f,
    0xf8,

    /* U+0063 "c" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0x80, 0x10, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x1f,
    0xf8,

    /* U+0064 "d" */
    0xff, 0xe0, 0xc, 0x31, 0x86, 0x30, 0xc6, 0x18,
    0xc3, 0x18, 0x63, 0x0, 0x20, 0x4, 0x31, 0x86,
    0x30, 0xc6, 0x18, 0xc3, 0x18, 0x63, 0x0, 0x7f,
    0xf8,

    /* U+0065 "e" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0xf, 0xff, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x1f,
    0xf8,

    /* U+0066 "f" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0x7f, 0xf8, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0,

    /* U+0067 "g" */
    0x7f, 0xd8, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x0, 0x7b, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xc0, 0x7f,
    0xf8,

    /* U+0068 "h" */
    0x0, 0x18, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x7b, 0xd8, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3,

    /* U+0069 "i" */
    0xff, 0xc0, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0x0, 0x0, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0x0, 0x3f, 0xf0,

    /* U+006A "j" */
    0x0, 0x20, 0xc, 0x1, 0x80, 0x30, 0x6, 0x0,
    0xc0, 0x18, 0x1, 0x80, 0x38, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xff, 0xc0,

    /* U+006B "k" */
    0xc0, 0x60, 0x70, 0x38, 0x3c, 0x1e, 0xb, 0x5,
    0x80, 0x7c, 0x60, 0x30, 0x58, 0x2c, 0x1e, 0x7,
    0x3, 0x80,

    /* U+006C "l" */
    0x80, 0x18, 0x3, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x4, 0x0, 0x80, 0x18, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xff, 0xc0,

    /* U+006D "m" */
    0xc0, 0x7c, 0x1f, 0x83, 0xf8, 0x7d, 0x9f, 0xb2,
    0xf2, 0x5c, 0x1, 0x80, 0x38, 0xcf, 0x19, 0xe3,
    0x3c, 0x67, 0x8c, 0xf1, 0x9e, 0x3,

    /* U+006E "n" */
    0xc0, 0x7c, 0xf, 0xc1, 0xf8, 0x3d, 0x7, 0xa0,
    0xf4, 0x1c, 0x1, 0x80, 0x38, 0x4f, 0x5, 0xe0,
    0xbc, 0x1f, 0x83, 0xf0, 0x3e, 0x3,

    /* U+006F "o" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x80, 0x30, 0x7, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xc0, 0x7f,
    0xf8,

    /* U+0070 "p" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x7b, 0xd8, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0,

    /* U+0071 "q" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x80, 0x30, 0x7, 0x1, 0xe0,
    0xbc, 0x17, 0x83, 0xf0, 0x7e, 0x7, 0xc0, 0xff,
    0xf8,

    /* U+0072 "r" */
    0x7f, 0xf8, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x7b, 0xd8, 0x3, 0x4, 0x60,
    0x8c, 0x19, 0x83, 0x30, 0x26, 0x4, 0x80, 0x0,

    /* U+0073 "s" */
    0x7f, 0xdc, 0x3, 0x80, 0x78, 0xf, 0x1, 0xa0,
    0x34, 0x6, 0x80, 0xc0, 0xf, 0x78, 0x1, 0x80,
    0xb0, 0x16, 0x2, 0xc0, 0x78, 0x7, 0x0, 0xef,
    0xf8,

    /* U+0074 "t" */
    0xff, 0xc3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x0, 0x0, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0,

    /* U+0075 "u" */
    0x80, 0x38, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1c, 0x1, 0x80, 0x38, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xff, 0xc0,

    /* U+0076 "v" */
    0xc0, 0x60, 0x70, 0x38, 0x3c, 0x1e, 0xb, 0x5,
    0x0, 0x80, 0x64, 0x36, 0x1b, 0xf, 0x7, 0x3,
    0x81, 0x80,

    /* U+0077 "w" */
    0xc0, 0x78, 0xcf, 0x19, 0xe3, 0x3c, 0x67, 0x8c,
    0xf1, 0x9c, 0x1, 0x80, 0x39, 0x2f, 0x65, 0xec,
    0xff, 0xf, 0xc1, 0xf8, 0x3e, 0x3,

    /* U+0078 "x" */
    0x83, 0x7, 0x1a, 0x24, 0x40, 0x0, 0x0, 0x0,
    0x89, 0x16, 0x38, 0x30, 0x40,

    /* U+0079 "y" */
    0x83, 0x7, 0xb, 0x36, 0x44, 0x80, 0x0, 0x18,
    0x30, 0x60, 0xc1, 0x83, 0x0,

    /* U+007A "z" */
    0xff, 0x80, 0x80, 0x40, 0x60, 0x30, 0x30, 0x18,
    0x8, 0x0, 0x0, 0x4, 0x6, 0x3, 0x3, 0x1,
    0x80, 0x80, 0x40, 0x7f, 0xc0,

    /* U+007C "|" */
    0xff, 0xf0, 0xff, 0xf0,

    /* U+007E "~" */
    0x7f, 0xfc, 0xdf, 0x9b, 0xfb, 0x7f, 0x6f, 0xbe,
    0xf7, 0xde, 0x7b, 0xcd, 0x6f, 0xfb, 0x3d, 0xe7,
    0xbd, 0xf7, 0xaf, 0xfd, 0xbf, 0x37, 0xe6, 0xff,
    0xf8
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 58, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 235, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 235, .box_w = 7, .box_h = 8, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 9, .adv_w = 235, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 58, .adv_w = 235, .box_w = 10, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 235, .box_w = 2, .box_h = 7, .ofs_x = 7, .ofs_y = 9},
    {.bitmap_index = 83, .adv_w = 235, .box_w = 3, .box_h = 14, .ofs_x = 9, .ofs_y = 2},
    {.bitmap_index = 89, .adv_w = 235, .box_w = 3, .box_h = 14, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 95, .adv_w = 235, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 113, .adv_w = 235, .box_w = 10, .box_h = 14, .ofs_x = 3, .ofs_y = 2},
    {.bitmap_index = 131, .adv_w = 235, .box_w = 3, .box_h = 6, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 134, .adv_w = 235, .box_w = 9, .box_h = 1, .ofs_x = 3, .ofs_y = 8},
    {.bitmap_index = 136, .adv_w = 0, .box_w = 2, .box_h = 1, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 235, .box_w = 7, .box_h = 14, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 150, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 235, .box_w = 2, .box_h = 17, .ofs_x = 11, .ofs_y = 1},
    {.bitmap_index = 180, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 252, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 324, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 349, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 58, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 377, .adv_w = 235, .box_w = 9, .box_h = 16, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 235, .box_w = 9, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 235, .box_w = 9, .box_h = 16, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 235, .box_w = 12, .box_h = 16, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 448, .adv_w = 235, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 497, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 597, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 619, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 644, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 666, .adv_w = 235, .box_w = 10, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 689, .adv_w = 235, .box_w = 11, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 713, .adv_w = 235, .box_w = 9, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 731, .adv_w = 235, .box_w = 11, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 755, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 777, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 799, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 824, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 846, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 871, .adv_w = 235, .box_w = 11, .box_h = 17, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 895, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 920, .adv_w = 235, .box_w = 10, .box_h = 15, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 939, .adv_w = 235, .box_w = 11, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 963, .adv_w = 235, .box_w = 9, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 981, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1003, .adv_w = 235, .box_w = 7, .box_h = 14, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 1016, .adv_w = 235, .box_w = 7, .box_h = 14, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 1029, .adv_w = 235, .box_w = 9, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1050, .adv_w = 235, .box_w = 7, .box_h = 14, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 1063, .adv_w = 235, .box_w = 5, .box_h = 8, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 1068, .adv_w = 235, .box_w = 9, .box_h = 1, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1070, .adv_w = 235, .box_w = 3, .box_h = 6, .ofs_x = 4, .ofs_y = 10},
    {.bitmap_index = 1073, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 1095, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1120, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1145, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1170, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1195, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 1217, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1242, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1264, .adv_w = 235, .box_w = 10, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1287, .adv_w = 235, .box_w = 11, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1311, .adv_w = 235, .box_w = 9, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1329, .adv_w = 235, .box_w = 11, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1353, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1375, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1397, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1422, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 1444, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1469, .adv_w = 235, .box_w = 11, .box_h = 17, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1493, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1518, .adv_w = 235, .box_w = 10, .box_h = 15, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 1537, .adv_w = 235, .box_w = 11, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1561, .adv_w = 235, .box_w = 9, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1579, .adv_w = 235, .box_w = 11, .box_h = 16, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1601, .adv_w = 235, .box_w = 7, .box_h = 14, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 1614, .adv_w = 235, .box_w = 7, .box_h = 14, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 1627, .adv_w = 235, .box_w = 9, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1648, .adv_w = 235, .box_w = 2, .box_h = 14, .ofs_x = 7, .ofs_y = 2},
    {.bitmap_index = 1652, .adv_w = 235, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_3[] = {
    0, 0, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 27, 28, 29, 0,
    30, 0, 31
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 3, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 36, .range_length = 23, .glyph_id_start = 4,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 60, .range_length = 31, .glyph_id_start = 27,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 92, .range_length = 35, .glyph_id_start = 58,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_3, .list_length = 35, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_14segment18 = {
#else
lv_font_t ui_font_14segment18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_14SEGMENT18*/


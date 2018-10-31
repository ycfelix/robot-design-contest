#ifndef __OLED_FONT_H
#define __OLED_FONT_H

#if FONT_WIDTH == 3 //3x7
static const unsigned char font[] = {
  0x7C,0x44,0x7C, // 0x00
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0xFF,0xFF,0xFF,

  0x00,0x00,0x00, //
  0x00,0x5c,0x00, // ! 
  0x0C,0x00,0x0C, // "
  0x7C,0x28,0x7C, // #
  0x28,0x7C,0x14, // $
  0x24,0x10,0x48, // %
  0x3C,0x5C,0x70, // &
  0x00,0x0C,0x00, // '
  0x00,0x38,0x44, // (
  0x44,0x38,0x00, // )
  0x14,0x08,0x14, // *
  0x10,0x38,0x10, // +
  0x40,0x20,0x00, // ,
  0x10,0x10,0x10, // -
  0x00,0x40,0x00, // .
  0x60,0x10,0x0C, // /
  0x78,0x44,0x3C, // 0
  0x08,0x7C,0x00, // 1
  0x64,0x54,0x48, // 2
  0x44,0x54,0x28, // 3
  0x1C,0x10,0x7C, // 4
  0x5C,0x54,0x24, // 5
  0x78,0x54,0x74, // 6
  0x64,0x14,0x0C, // 7
  0x7C,0x54,0x7C, // 8
  0x5C,0x54,0x3C, // 9
  0x00,0x28,0x00, // :
  0x40,0x28,0x00, // ;
  0x10,0x28,0x44, // <
  0x28,0x28,0x28, // =
  0x44,0x28,0x10, // >
  0x04,0x54,0x0C, // ?

  0x38,0x54,0x58, // @
  0x78,0x14,0x78, // A
  0x7C,0x54,0x28, // B
  0x38,0x44,0x44, // C
  0x7C,0x44,0x38, // D
  0x7C,0x54,0x54, // E
  0x7C,0x14,0x14, // F
  0x38,0x54,0x74, // G
  0x7C,0x10,0x7C, // H
  0x44,0x7C,0x44, // I
  0x20,0x40,0x3C, // J
  0x7C,0x10,0x6C, // K
  0x7C,0x40,0x40, // L
  0x7C,0x18,0x7C, // M
  0x7C,0x38,0x7C, // N
  0x38,0x44,0x38, // O
  0x7C,0x14,0x08, // P
  0x38,0x64,0x78, // Q
  0x7C,0x34,0x58, // R
  0x48,0x54,0x24, // S
  0x04,0x7C,0x04, // T
  0x3C,0x40,0x7C, // U
  0x1C,0x20,0x1C, // V
  0x7C,0x30,0x7C, // W
  0x6C,0x10,0x6C, // X
  0x0C,0x70,0x0C, // Y
  0x64,0x54,0x4C, // Z
  0x7C,0x44,0x44, // [
  0x08,0x10,0x20, // (backspace)
  0x44,0x44,0x7C, // ]
  0x08,0x04,0x08, // ^
  0x40,0x40,0x40, // _

  0x04,0x08,0x00, // `
  0x68,0x58,0x70, // a
  0x7C,0x48,0x30, // b
  0x30,0x48,0x48, // c
  0x30,0x48,0x7C, // d
  0x30,0x68,0x58, // e
  0x10,0x78,0x14, // f
  0x30,0xA8,0x78, // g
  0x7C,0x08,0x70, // h
  0x00,0x74,0x00, // i
  0x40,0x80,0x74, // j
  0x7C,0x30,0x48, // k
  0x44,0x7C,0x40, // l
  0x78,0x38,0x78, // m
  0x78,0x08,0x70, // n
  0x30,0x48,0x30, // o
  0xF8,0x48,0x30, // p
  0x30,0x48,0xF8, // q
  0x70,0x08,0x08, // r
  0x50,0x78,0x28, // s
  0x08,0x7C,0x48, // t
  0x38,0x40,0x78, // u
  0x38,0x60,0x38, // v
  0x78,0x70,0x78, // w
  0x48,0x30,0x48, // x
  0x18,0xA0,0x78, // y
  0x68,0x78,0x58, // z
  0x10,0x6C,0x44, // {
  0x00,0x6C,0x00, // |
  0x44,0x6C,0x10, // }
  0x08,0x0C,0x04, //
  0x7C,0x7C,0x7C, //

  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,

  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,

  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,

  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C,
  0x7C,0x44,0x7C
};
#endif

#if FONT_WIDTH == 5 //5x7
static const unsigned char font[] = {
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x3E, 0x5B, 0x4F, 0x5B, 0x3E,
  0x3E, 0x6B, 0x4F, 0x6B, 0x3E,
  0x1C, 0x3E, 0x7C, 0x3E, 0x1C,
  0x18, 0x3C, 0x7E, 0x3C, 0x18,
  0x1C, 0x57, 0x7D, 0x57, 0x1C,
  0x1C, 0x5E, 0x7F, 0x5E, 0x1C,
  0x00, 0x18, 0x3C, 0x18, 0x00,
  0xFF, 0xE7, 0xC3, 0xE7, 0xFF,
  0x00, 0x18, 0x24, 0x18, 0x00,
  0xFF, 0xE7, 0xDB, 0xE7, 0xFF,
  0x30, 0x48, 0x3A, 0x06, 0x0E,
  0x26, 0x29, 0x79, 0x29, 0x26,
  0x40, 0x7F, 0x05, 0x05, 0x07,
  0x40, 0x7F, 0x05, 0x25, 0x3F,
  0x5A, 0x3C, 0xE7, 0x3C, 0x5A,
  0x7F, 0x3E, 0x1C, 0x1C, 0x08,
  0x08, 0x1C, 0x1C, 0x3E, 0x7F,
  0x14, 0x22, 0x7F, 0x22, 0x14,
  0x5F, 0x5F, 0x00, 0x5F, 0x5F,
  0x06, 0x09, 0x7F, 0x01, 0x7F,
  0x00, 0x66, 0x89, 0x95, 0x6A,
  0x60, 0x60, 0x60, 0x60, 0x60,
  0x94, 0xA2, 0xFF, 0xA2, 0x94,
  0x08, 0x04, 0x7E, 0x04, 0x08,
  0x10, 0x20, 0x7E, 0x20, 0x10,
  0x08, 0x08, 0x2A, 0x1C, 0x08,
  0x08, 0x1C, 0x2A, 0x08, 0x08,
  0x1E, 0x10, 0x10, 0x10, 0x10,
  0x0C, 0x1E, 0x0C, 0x1E, 0x0C,
  0x30, 0x38, 0x3E, 0x38, 0x30,
  0x06, 0x0E, 0x3E, 0x0E, 0x06,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x5F, 0x00, 0x00,
  0x00, 0x07, 0x00, 0x07, 0x00,
  0x14, 0x7F, 0x14, 0x7F, 0x14,
  0x24, 0x2A, 0x7F, 0x2A, 0x12,
  0x23, 0x13, 0x08, 0x64, 0x62,
  0x36, 0x49, 0x56, 0x20, 0x50,
  0x00, 0x08, 0x07, 0x03, 0x00,
  0x00, 0x1C, 0x22, 0x41, 0x00,
  0x00, 0x41, 0x22, 0x1C, 0x00,
  0x2A, 0x1C, 0x7F, 0x1C, 0x2A,
  0x08, 0x08, 0x3E, 0x08, 0x08,
  0x00, 0x80, 0x70, 0x30, 0x00,
  0x08, 0x08, 0x08, 0x08, 0x08,
  0x00, 0x00, 0x60, 0x60, 0x00,
  0x20, 0x10, 0x08, 0x04, 0x02,
  0x3E, 0x51, 0x49, 0x45, 0x3E,
  0x00, 0x42, 0x7F, 0x40, 0x00,
  0x72, 0x49, 0x49, 0x49, 0x46,
  0x21, 0x41, 0x49, 0x4D, 0x33,
  0x18, 0x14, 0x12, 0x7F, 0x10,
  0x27, 0x45, 0x45, 0x45, 0x39,
  0x3C, 0x4A, 0x49, 0x49, 0x31,
  0x41, 0x21, 0x11, 0x09, 0x07,
  0x36, 0x49, 0x49, 0x49, 0x36,
  0x46, 0x49, 0x49, 0x29, 0x1E,
  0x00, 0x00, 0x14, 0x00, 0x00,
  0x00, 0x40, 0x34, 0x00, 0x00,
  0x00, 0x08, 0x14, 0x22, 0x41,
  0x14, 0x14, 0x14, 0x14, 0x14,
  0x00, 0x41, 0x22, 0x14, 0x08,
  0x02, 0x01, 0x59, 0x09, 0x06,
  0x3E, 0x41, 0x5D, 0x59, 0x4E,
  0x7C, 0x12, 0x11, 0x12, 0x7C,
  0x7F, 0x49, 0x49, 0x49, 0x36,
  0x3E, 0x41, 0x41, 0x41, 0x22,
  0x7F, 0x41, 0x41, 0x41, 0x3E,
  0x7F, 0x49, 0x49, 0x49, 0x41,
  0x7F, 0x09, 0x09, 0x09, 0x01,
  0x3E, 0x41, 0x41, 0x51, 0x73,
  0x7F, 0x08, 0x08, 0x08, 0x7F,
  0x00, 0x41, 0x7F, 0x41, 0x00,
  0x20, 0x40, 0x41, 0x3F, 0x01,
  0x7F, 0x08, 0x14, 0x22, 0x41,
  0x7F, 0x40, 0x40, 0x40, 0x40,
  0x7F, 0x02, 0x1C, 0x02, 0x7F,
  0x7F, 0x04, 0x08, 0x10, 0x7F,
  0x3E, 0x41, 0x41, 0x41, 0x3E,
  0x7F, 0x09, 0x09, 0x09, 0x06,
  0x3E, 0x41, 0x51, 0x21, 0x5E,
  0x7F, 0x09, 0x19, 0x29, 0x46,
  0x26, 0x49, 0x49, 0x49, 0x32,
  0x03, 0x01, 0x7F, 0x01, 0x03,
  0x3F, 0x40, 0x40, 0x40, 0x3F,
  0x1F, 0x20, 0x40, 0x20, 0x1F,
  0x3F, 0x40, 0x38, 0x40, 0x3F,
  0x63, 0x14, 0x08, 0x14, 0x63,
  0x03, 0x04, 0x78, 0x04, 0x03,
  0x61, 0x59, 0x49, 0x4D, 0x43,
  0x00, 0x7F, 0x41, 0x41, 0x41,
  0x02, 0x04, 0x08, 0x10, 0x20,
  0x00, 0x41, 0x41, 0x41, 0x7F,
  0x04, 0x02, 0x01, 0x02, 0x04,
  0x40, 0x40, 0x40, 0x40, 0x40,
  0x00, 0x03, 0x07, 0x08, 0x00,
  0x20, 0x54, 0x54, 0x78, 0x40,
  0x7F, 0x28, 0x44, 0x44, 0x38,
  0x38, 0x44, 0x44, 0x44, 0x28,
  0x38, 0x44, 0x44, 0x28, 0x7F,
  0x38, 0x54, 0x54, 0x54, 0x18,
  0x00, 0x08, 0x7E, 0x09, 0x02,
  0x18, 0xA4, 0xA4, 0x9C, 0x78,
  0x7F, 0x08, 0x04, 0x04, 0x78,
  0x00, 0x44, 0x7D, 0x40, 0x00,
  0x20, 0x40, 0x40, 0x3D, 0x00,
  0x7F, 0x10, 0x28, 0x44, 0x00,
  0x00, 0x41, 0x7F, 0x40, 0x00,
  0x7C, 0x04, 0x78, 0x04, 0x78,
  0x7C, 0x08, 0x04, 0x04, 0x78,
  0x38, 0x44, 0x44, 0x44, 0x38,
  0xFC, 0x18, 0x24, 0x24, 0x18,
  0x18, 0x24, 0x24, 0x18, 0xFC,
  0x7C, 0x08, 0x04, 0x04, 0x08,
  0x48, 0x54, 0x54, 0x54, 0x24,
  0x04, 0x04, 0x3F, 0x44, 0x24,
  0x3C, 0x40, 0x40, 0x20, 0x7C,
  0x1C, 0x20, 0x40, 0x20, 0x1C,
  0x3C, 0x40, 0x30, 0x40, 0x3C,
  0x44, 0x28, 0x10, 0x28, 0x44,
  0x4C, 0x90, 0x90, 0x90, 0x7C,
  0x44, 0x64, 0x54, 0x4C, 0x44,
  0x00, 0x08, 0x36, 0x41, 0x00,
  0x00, 0x00, 0x77, 0x00, 0x00,
  0x00, 0x41, 0x36, 0x08, 0x00,
  0x02, 0x01, 0x02, 0x04, 0x02,
  0x3C, 0x26, 0x23, 0x26, 0x3C,
  0x1E, 0xA1, 0xA1, 0x61, 0x12,
  0x3A, 0x40, 0x40, 0x20, 0x7A,
  0x38, 0x54, 0x54, 0x55, 0x59,
  0x21, 0x55, 0x55, 0x79, 0x41,
  0x22, 0x54, 0x54, 0x78, 0x42, // a-umlaut
  0x21, 0x55, 0x54, 0x78, 0x40,
  0x20, 0x54, 0x55, 0x79, 0x40,
  0x0C, 0x1E, 0x52, 0x72, 0x12,
  0x39, 0x55, 0x55, 0x55, 0x59,
  0x39, 0x54, 0x54, 0x54, 0x59,
  0x39, 0x55, 0x54, 0x54, 0x58,
  0x00, 0x00, 0x45, 0x7C, 0x41,
  0x00, 0x02, 0x45, 0x7D, 0x42,
  0x00, 0x01, 0x45, 0x7C, 0x40,
  0x7D, 0x12, 0x11, 0x12, 0x7D, // A-umlaut
  0xF0, 0x28, 0x25, 0x28, 0xF0,
  0x7C, 0x54, 0x55, 0x45, 0x00,
  0x20, 0x54, 0x54, 0x7C, 0x54,
  0x7C, 0x0A, 0x09, 0x7F, 0x49,
  0x32, 0x49, 0x49, 0x49, 0x32,
  0x3A, 0x44, 0x44, 0x44, 0x3A, // o-umlaut
  0x32, 0x4A, 0x48, 0x48, 0x30,
  0x3A, 0x41, 0x41, 0x21, 0x7A,
  0x3A, 0x42, 0x40, 0x20, 0x78,
  0x00, 0x9D, 0xA0, 0xA0, 0x7D,
  0x3D, 0x42, 0x42, 0x42, 0x3D, // O-umlaut
  0x3D, 0x40, 0x40, 0x40, 0x3D,
  0x3C, 0x24, 0xFF, 0x24, 0x24,
  0x48, 0x7E, 0x49, 0x43, 0x66,
  0x2B, 0x2F, 0xFC, 0x2F, 0x2B,
  0xFF, 0x09, 0x29, 0xF6, 0x20,
  0xC0, 0x88, 0x7E, 0x09, 0x03,
  0x20, 0x54, 0x54, 0x79, 0x41,
  0x00, 0x00, 0x44, 0x7D, 0x41,
  0x30, 0x48, 0x48, 0x4A, 0x32,
  0x38, 0x40, 0x40, 0x22, 0x7A,
  0x00, 0x7A, 0x0A, 0x0A, 0x72,
  0x7D, 0x0D, 0x19, 0x31, 0x7D,
  0x26, 0x29, 0x29, 0x2F, 0x28,
  0x26, 0x29, 0x29, 0x29, 0x26,
  0x30, 0x48, 0x4D, 0x40, 0x20,
  0x38, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x38,
  0x2F, 0x10, 0xC8, 0xAC, 0xBA,
  0x2F, 0x10, 0x28, 0x34, 0xFA,
  0x00, 0x00, 0x7B, 0x00, 0x00,
  0x08, 0x14, 0x2A, 0x14, 0x22,
  0x22, 0x14, 0x2A, 0x14, 0x08,
  0x55, 0x00, 0x55, 0x00, 0x55, // #176 (25% block) missing in old code
  0xAA, 0x55, 0xAA, 0x55, 0xAA, // 50% block
  0xFF, 0x55, 0xFF, 0x55, 0xFF, // 75% block
  0x00, 0x00, 0x00, 0xFF, 0x00,
  0x10, 0x10, 0x10, 0xFF, 0x00,
  0x14, 0x14, 0x14, 0xFF, 0x00,
  0x10, 0x10, 0xFF, 0x00, 0xFF,
  0x10, 0x10, 0xF0, 0x10, 0xF0,
  0x14, 0x14, 0x14, 0xFC, 0x00,
  0x14, 0x14, 0xF7, 0x00, 0xFF,
  0x00, 0x00, 0xFF, 0x00, 0xFF,
  0x14, 0x14, 0xF4, 0x04, 0xFC,
  0x14, 0x14, 0x17, 0x10, 0x1F,
  0x10, 0x10, 0x1F, 0x10, 0x1F,
  0x14, 0x14, 0x14, 0x1F, 0x00,
  0x10, 0x10, 0x10, 0xF0, 0x00,
  0x00, 0x00, 0x00, 0x1F, 0x10,
  0x10, 0x10, 0x10, 0x1F, 0x10,
  0x10, 0x10, 0x10, 0xF0, 0x10,
  0x00, 0x00, 0x00, 0xFF, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0xFF, 0x10,
  0x00, 0x00, 0x00, 0xFF, 0x14,
  0x00, 0x00, 0xFF, 0x00, 0xFF,
  0x00, 0x00, 0x1F, 0x10, 0x17,
  0x00, 0x00, 0xFC, 0x04, 0xF4,
  0x14, 0x14, 0x17, 0x10, 0x17,
  0x14, 0x14, 0xF4, 0x04, 0xF4,
  0x00, 0x00, 0xFF, 0x00, 0xF7,
  0x14, 0x14, 0x14, 0x14, 0x14,
  0x14, 0x14, 0xF7, 0x00, 0xF7,
  0x14, 0x14, 0x14, 0x17, 0x14,
  0x10, 0x10, 0x1F, 0x10, 0x1F,
  0x14, 0x14, 0x14, 0xF4, 0x14,
  0x10, 0x10, 0xF0, 0x10, 0xF0,
  0x00, 0x00, 0x1F, 0x10, 0x1F,
  0x00, 0x00, 0x00, 0x1F, 0x14,
  0x00, 0x00, 0x00, 0xFC, 0x14,
  0x00, 0x00, 0xF0, 0x10, 0xF0,
  0x10, 0x10, 0xFF, 0x10, 0xFF,
  0x14, 0x14, 0x14, 0xFF, 0x14,
  0x10, 0x10, 0x10, 0x1F, 0x00,
  0x00, 0x00, 0x00, 0xF0, 0x10,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
  0xFF, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0xFF,
  0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
  0x38, 0x44, 0x44, 0x38, 0x44,
  0xFC, 0x4A, 0x4A, 0x4A, 0x34, // sharp-s or beta
  0x7E, 0x02, 0x02, 0x06, 0x06,
  0x02, 0x7E, 0x02, 0x7E, 0x02,
  0x63, 0x55, 0x49, 0x41, 0x63,
  0x38, 0x44, 0x44, 0x3C, 0x04,
  0x40, 0x7E, 0x20, 0x1E, 0x20,
  0x06, 0x02, 0x7E, 0x02, 0x02,
  0x99, 0xA5, 0xE7, 0xA5, 0x99,
  0x1C, 0x2A, 0x49, 0x2A, 0x1C,
  0x4C, 0x72, 0x01, 0x72, 0x4C,
  0x30, 0x4A, 0x4D, 0x4D, 0x30,
  0x30, 0x48, 0x78, 0x48, 0x30,
  0xBC, 0x62, 0x5A, 0x46, 0x3D,
  0x3E, 0x49, 0x49, 0x49, 0x00,
  0x7E, 0x01, 0x01, 0x01, 0x7E,
  0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
  0x44, 0x44, 0x5F, 0x44, 0x44,
  0x40, 0x51, 0x4A, 0x44, 0x40,
  0x40, 0x44, 0x4A, 0x51, 0x40,
  0x00, 0x00, 0xFF, 0x01, 0x03,
  0xE0, 0x80, 0xFF, 0x00, 0x00,
  0x08, 0x08, 0x6B, 0x6B, 0x08,
  0x36, 0x12, 0x36, 0x24, 0x36,
  0x06, 0x0F, 0x09, 0x0F, 0x06,
  0x00, 0x00, 0x18, 0x18, 0x00,
  0x00, 0x00, 0x10, 0x10, 0x00,
  0x30, 0x40, 0xFF, 0x01, 0x01,
  0x00, 0x1F, 0x01, 0x01, 0x1E,
  0x00, 0x19, 0x1D, 0x17, 0x12,
  0x00, 0x3C, 0x3C, 0x3C, 0x3C,
  0x00, 0x00, 0x00, 0x00, 0x00  // #255 NBSP
};
#endif

#if FONT_WIDTH == 6

#ifndef ALT_FONT
static const unsigned char font[]= {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
  0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, // !
  0x00, 0x00, 0x07, 0x00, 0x07, 0x00, // "
  0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14, // #
  0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12, // $
  0x00, 0x23, 0x13, 0x08, 0x64, 0x62, // %
  0x00, 0x36, 0x49, 0x55, 0x22, 0x50, // &
  0x00, 0x00, 0x05, 0x03, 0x00, 0x00, // '
  0x00, 0x00, 0x1c, 0x22, 0x41, 0x00, // (
  0x00, 0x00, 0x41, 0x22, 0x1c, 0x00, // )
  0x00, 0x14, 0x08, 0x3E, 0x08, 0x14, // *
  0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, // +
  0x00, 0x00, 0x00, 0xA0, 0x60, 0x00, // ,
  0x00, 0x08, 0x08, 0x08, 0x08, 0x08, // -
  0x00, 0x00, 0x60, 0x60, 0x00, 0x00, // .
  0x00, 0x20, 0x10, 0x08, 0x04, 0x02, // /
  0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
  0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, // 1
  0x00, 0x42, 0x61, 0x51, 0x49, 0x46, // 2
  0x00, 0x21, 0x41, 0x45, 0x4B, 0x31, // 3
  0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, // 4
  0x00, 0x27, 0x45, 0x45, 0x45, 0x39, // 5
  0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
  0x00, 0x01, 0x71, 0x09, 0x05, 0x03, // 7
  0x00, 0x36, 0x49, 0x49, 0x49, 0x36, // 8
  0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, // 9
  0x00, 0x00, 0x36, 0x36, 0x00, 0x00, // :
  0x00, 0x00, 0x56, 0x36, 0x00, 0x00, // ;
  0x00, 0x08, 0x14, 0x22, 0x41, 0x00, // <
  0x00, 0x14, 0x14, 0x14, 0x14, 0x14, // =
  0x00, 0x00, 0x41, 0x22, 0x14, 0x08, // >
  0x00, 0x02, 0x01, 0x51, 0x09, 0x06, // ?
  0x00, 0x32, 0x49, 0x59, 0x51, 0x3E, // @
  0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C, // A
  0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, // B
  0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, // C
  0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, // D
  0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, // E
  0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, // F
  0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A, // G
  0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, // H
  0x00, 0x00, 0x41, 0x7F, 0x41, 0x00, // I
  0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, // J
  0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, // K
  0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, // L
  0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
  0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, // N
  0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, // O
  0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, // P
  0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
  0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, // R
  0x00, 0x46, 0x49, 0x49, 0x49, 0x31, // S
  0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, // T
  0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, // U
  0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, // V
  0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, // W
  0x00, 0x63, 0x14, 0x08, 0x14, 0x63, // X
  0x00, 0x07, 0x08, 0x70, 0x08, 0x07, // Y
  0x00, 0x61, 0x51, 0x49, 0x45, 0x43, // Z
  0x00, 0x00, 0x7F, 0x41, 0x41, 0x00, // [
  0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55, // 55
  0x00, 0x00, 0x41, 0x41, 0x7F, 0x00, // ]
  0x00, 0x04, 0x02, 0x01, 0x02, 0x04, // ^
  0x00, 0x40, 0x40, 0x40, 0x40, 0x40, // _
  0x00, 0x00, 0x01, 0x02, 0x04, 0x00, // '
  0x00, 0x20, 0x54, 0x54, 0x54, 0x78, // a
  0x00, 0x7F, 0x48, 0x44, 0x44, 0x38, // b
  0x00, 0x38, 0x44, 0x44, 0x44, 0x20, // c
  0x00, 0x38, 0x44, 0x44, 0x48, 0x7F, // d
  0x00, 0x38, 0x54, 0x54, 0x54, 0x18, // e
  0x00, 0x08, 0x7E, 0x09, 0x01, 0x02, // f
  0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C, // g
  0x00, 0x7F, 0x08, 0x04, 0x04, 0x78, // h
  0x00, 0x00, 0x44, 0x7D, 0x40, 0x00, // i
  0x00, 0x40, 0x80, 0x84, 0x7D, 0x00, // j
  0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, // k
  0x00, 0x00, 0x41, 0x7F, 0x40, 0x00, // l
  0x00, 0x7C, 0x04, 0x18, 0x04, 0x78, // m
  0x00, 0x7C, 0x08, 0x04, 0x04, 0x78, // n
  0x00, 0x38, 0x44, 0x44, 0x44, 0x38, // o
  0x00, 0xFC, 0x24, 0x24, 0x24, 0x18, // p
  0x00, 0x18, 0x24, 0x24, 0x18, 0xFC, // q
  0x00, 0x7C, 0x08, 0x04, 0x04, 0x08, // r
  0x00, 0x48, 0x54, 0x54, 0x54, 0x20, // s
  0x00, 0x04, 0x3F, 0x44, 0x40, 0x20, // t
  0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C, // u
  0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, // v
  0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, // w
  0x00, 0x44, 0x28, 0x10, 0x28, 0x44, // x
  0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C, // y
  0x00, 0x44, 0x64, 0x54, 0x4C, 0x44, // z
  0x00, 0x00, 0x08, 0x77, 0x00, 0x00, // {
  0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, // |
  0x00, 0x00, 0x77, 0x08, 0x00, 0x00, // }
  0x00, 0x10, 0x08, 0x10, 0x08, 0x00, // ~
  0x14, 0x14, 0x14, 0x14, 0x14, 0x14, // horiz lines // DEL
};
#endif

#ifdef ALT_FONT
static const unsigned char font []= {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, // !
    0x00, 0x00, 0x07, 0x00, 0x07, 0x00, // "
    0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14, // #
    0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12, // $
    0x00, 0x23, 0x13, 0x08, 0x64, 0x62, // %
    0x00, 0x36, 0x49, 0x55, 0x22, 0x50, // &
    0x00, 0x00, 0x05, 0x03, 0x00, 0x00, // '
    0x00, 0x00, 0x1c, 0x22, 0x41, 0x00, // (
    0x00, 0x00, 0x41, 0x22, 0x1c, 0x00, // )
    0x00, 0x14, 0x08, 0x3E, 0x08, 0x14, // *
    0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, // +
    0x00, 0x00, 0x00, 0xA0, 0x60, 0x00, // ,
    0x00, 0x08, 0x08, 0x08, 0x08, 0x08, // -
    0x00, 0x00, 0x60, 0x60, 0x00, 0x00, // .
    0x00, 0x20, 0x10, 0x08, 0x04, 0x02, // /
    0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
    0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, // 1
    0x00, 0x42, 0x61, 0x51, 0x49, 0x46, // 2
    0x00, 0x21, 0x41, 0x45, 0x4B, 0x31, // 3
    0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, // 4
    0x00, 0x27, 0x45, 0x45, 0x45, 0x39, // 5
    0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
    0x00, 0x01, 0x71, 0x09, 0x05, 0x03, // 7
    0x00, 0x36, 0x49, 0x49, 0x49, 0x36, // 8
    0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, // 9
    0x00, 0x00, 0x36, 0x36, 0x00, 0x00, // :
    0x00, 0x00, 0x56, 0x36, 0x00, 0x00, // ;
    0x00, 0x08, 0x14, 0x22, 0x41, 0x00, // <
    0x00, 0x14, 0x14, 0x14, 0x14, 0x14, // =
    0x00, 0x00, 0x41, 0x22, 0x14, 0x08, // >
    0x00, 0x02, 0x01, 0x51, 0x09, 0x06, // ?
    0x00, 0x32, 0x49, 0x59, 0x51, 0x3E, // @
    0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C, // A
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, // B
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, // C
    0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, // D
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, // E
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, // F
    0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A, // G
    0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, // H
    0x00, 0x00, 0x41, 0x7F, 0x41, 0x00, // I
    0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, // J
    0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, // K
    0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, // L
    0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
    0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, // N
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, // O
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, // P
    0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
    0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, // R
    0x00, 0x46, 0x49, 0x49, 0x49, 0x31, // S
    0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, // T
    0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, // U
    0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, // V
    0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, // W
    0x00, 0x63, 0x14, 0x08, 0x14, 0x63, // X
    0x00, 0x07, 0x08, 0x70, 0x08, 0x07, // Y
    0x00, 0x61, 0x51, 0x49, 0x45, 0x43, // Z
    0x00, 0x00, 0x7F, 0x41, 0x41, 0x00, // [
    0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55, // 55
    0x00, 0x00, 0x41, 0x41, 0x7F, 0x00, // ]
    0x00, 0x04, 0x02, 0x01, 0x02, 0x04, // ^
    0x00, 0x40, 0x40, 0x40, 0x40, 0x40, // _
    0x00, 0x00, 0x01, 0x02, 0x04, 0x00, // '
};
#endif

#endif

#if FONT_WIDTH == 8

static const unsigned char font[] = {
        0x00, 0x3E, 0x7F, 0x41, 0x4D, 0x4F, 0x2E, 0x00,    // Char 000 (.)
        0x00, 0x20, 0x74, 0x54, 0x54, 0x7C, 0x78, 0x00,    // Char 001 (.)
        0x00, 0x7E, 0x7E, 0x48, 0x48, 0x78, 0x30, 0x00,    // Char 002 (.)
        0x00, 0x38, 0x7C, 0x44, 0x44, 0x44, 0x00, 0x00,    // Char 003 (.)
        0x00, 0x30, 0x78, 0x48, 0x48, 0x7E, 0x7E, 0x00,    // Char 004 (.)
        0x00, 0x38, 0x7C, 0x54, 0x54, 0x5C, 0x18, 0x00,    // Char 005 (.)
        0x00, 0x00, 0x08, 0x7C, 0x7E, 0x0A, 0x0A, 0x00,    // Char 006 (.)
        0x00, 0x98, 0xBC, 0xA4, 0xA4, 0xFC, 0x7C, 0x00,    // Char 007 (.)
        0x00, 0x7E, 0x7E, 0x08, 0x08, 0x78, 0x70, 0x00,    // Char 008 (.)
        0x00, 0x00, 0x48, 0x7A, 0x7A, 0x40, 0x00, 0x00,    // Char 009 (.)
        0x00, 0x00, 0x80, 0x80, 0x80, 0xFA, 0x7A, 0x00,    // Char 010 (.)
        0x00, 0x7E, 0x7E, 0x10, 0x38, 0x68, 0x40, 0x00,    // Char 011 (.)
        0x00, 0x00, 0x42, 0x7E, 0x7E, 0x40, 0x00, 0x00,    // Char 012 (.)
        0x00, 0x7C, 0x7C, 0x18, 0x38, 0x1C, 0x7C, 0x78,    // Char 013 (.)
        0x00, 0x7C, 0x7C, 0x04, 0x04, 0x7C, 0x78, 0x00,    // Char 014 (.)
        0x00, 0x38, 0x7C, 0x44, 0x44, 0x7C, 0x38, 0x00,    // Char 015 (.)
        0x00, 0xFC, 0xFC, 0x24, 0x24, 0x3C, 0x18, 0x00,    // Char 016 (.)
        0x00, 0x18, 0x3C, 0x24, 0x24, 0xFC, 0xFC, 0x00,    // Char 017 (.)
        0x00, 0x7C, 0x7C, 0x04, 0x04, 0x0C, 0x08, 0x00,    // Char 018 (.)
        0x00, 0x48, 0x5C, 0x54, 0x54, 0x74, 0x24, 0x00,    // Char 019 (.)
        0x00, 0x04, 0x04, 0x3E, 0x7E, 0x44, 0x44, 0x00,    // Char 020 (.)
        0x00, 0x3C, 0x7C, 0x40, 0x40, 0x7C, 0x7C, 0x00,    // Char 021 (.)
        0x00, 0x1C, 0x3C, 0x60, 0x60, 0x3C, 0x1C, 0x00,    // Char 022 (.)
        0x00, 0x1C, 0x7C, 0x70, 0x38, 0x70, 0x7C, 0x1C,    // Char 023 (.)
        0x00, 0x44, 0x6C, 0x38, 0x38, 0x6C, 0x44, 0x00,    // Char 024 (.)
        0x00, 0x9C, 0xBC, 0xA0, 0xE0, 0x7C, 0x3C, 0x00,    // Char 025 (.)
        0x00, 0x44, 0x64, 0x74, 0x5C, 0x4C, 0x44, 0x00,    // Char 026 (.)
        0x00, 0x00, 0x7F, 0x7F, 0x41, 0x41, 0x00, 0x00,    // Char 027 (.)
        0x40, 0x68, 0x7C, 0x5E, 0x49, 0x49, 0x22, 0x00,    // Char 028 (.)
        0x00, 0x00, 0x41, 0x41, 0x7F, 0x7F, 0x00, 0x00,    // Char 029 (.)
        0x00, 0x08, 0x0C, 0xFE, 0xFE, 0x0C, 0x08, 0x00,    // Char 030 (.)
        0x00, 0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x18,    // Char 031 (.)
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    // Char 032 ( )
        0x00, 0x00, 0x00, 0x4F, 0x4F, 0x00, 0x00, 0x00,    // Char 033 (!)
        0x00, 0x07, 0x07, 0x00, 0x00, 0x07, 0x07, 0x00,    // Char 034 (")
        0x14, 0x7F, 0x7F, 0x14, 0x14, 0x7F, 0x7F, 0x14,    // Char 035 (#)
        0x00, 0x24, 0x2E, 0x6B, 0x6B, 0x3A, 0x12, 0x00,    // Char 036 ($)
        0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00,    // Char 037 (%)
        0x00, 0x32, 0x7F, 0x4D, 0x4D, 0x77, 0x72, 0x50,    // Char 038 (&)
        0x00, 0x00, 0x00, 0x04, 0x06, 0x03, 0x01, 0x00,    // Char 039 (')
        0x00, 0x00, 0x1C, 0x3E, 0x63, 0x41, 0x00, 0x00,    // Char 040 (()
        0x00, 0x00, 0x41, 0x63, 0x3E, 0x1C, 0x00, 0x00,    // Char 041 ())
        0x08, 0x2A, 0x3E, 0x1C, 0x1C, 0x3E, 0x2A, 0x08,    // Char 042 (*)
        0x00, 0x08, 0x08, 0x3E, 0x3E, 0x08, 0x08, 0x00,    // Char 043 (+)
        0x00, 0x00, 0x80, 0xE0, 0x60, 0x00, 0x00, 0x00,    // Char 044 (,)
        0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00,    // Char 045 (-)
        0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00,    // Char 046 (.)
        0x00, 0x40, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x02,    // Char 047 (/)
        0x00, 0x3E, 0x7F, 0x49, 0x45, 0x7F, 0x3E, 0x00,    // Char 048 (0)
        0x00, 0x40, 0x44, 0x7F, 0x7F, 0x40, 0x40, 0x00,    // Char 049 (1)
        0x00, 0x62, 0x73, 0x51, 0x49, 0x4F, 0x46, 0x00,    // Char 050 (2)
        0x00, 0x22, 0x63, 0x49, 0x49, 0x7F, 0x36, 0x00,    // Char 051 (3)
        0x00, 0x18, 0x18, 0x14, 0x16, 0x7F, 0x7F, 0x10,    // Char 052 (4)
        0x00, 0x27, 0x67, 0x45, 0x45, 0x7D, 0x39, 0x00,    // Char 053 (5)
        0x00, 0x3E, 0x7F, 0x49, 0x49, 0x7B, 0x32, 0x00,    // Char 054 (6)
        0x00, 0x03, 0x03, 0x79, 0x7D, 0x07, 0x03, 0x00,    // Char 055 (7)
        0x00, 0x36, 0x7F, 0x49, 0x49, 0x7F, 0x36, 0x00,    // Char 056 (8)
        0x00, 0x26, 0x6F, 0x49, 0x49, 0x7F, 0x3E, 0x00,    // Char 057 (9)
        0x00, 0x00, 0x00, 0x24, 0x24, 0x00, 0x00, 0x00,    // Char 058 (:)
        0x00, 0x00, 0x80, 0xE4, 0x64, 0x00, 0x00, 0x00,    // Char 059 (;)
        0x00, 0x08, 0x1C, 0x36, 0x63, 0x41, 0x41, 0x00,    // Char 060 (<)
        0x00, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x00,    // Char 061 (=)
        0x00, 0x41, 0x41, 0x63, 0x36, 0x1C, 0x08, 0x00,    // Char 062 (>)
        0x00, 0x02, 0x03, 0x51, 0x59, 0x0F, 0x06, 0x00,    // Char 063 (?)
        0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,    // Char 064 (@)
        0x00, 0x7C, 0x7E, 0x0B, 0x0B, 0x7E, 0x7C, 0x00,    // Char 065 (A)
        0x00, 0x7F, 0x7F, 0x49, 0x49, 0x7F, 0x36, 0x00,    // Char 066 (B)
        0x00, 0x3E, 0x7F, 0x41, 0x41, 0x63, 0x22, 0x00,    // Char 067 (C)
        0x00, 0x7F, 0x7F, 0x41, 0x63, 0x3E, 0x1C, 0x00,    // Char 068 (D)
        0x00, 0x7F, 0x7F, 0x49, 0x49, 0x41, 0x41, 0x00,    // Char 069 (E)
        0x00, 0x7F, 0x7F, 0x09, 0x09, 0x01, 0x01, 0x00,    // Char 070 (F)
        0x00, 0x3E, 0x7F, 0x41, 0x49, 0x7B, 0x3A, 0x00,    // Char 071 (G)
        0x00, 0x7F, 0x7F, 0x08, 0x08, 0x7F, 0x7F, 0x00,    // Char 072 (H)
        0x00, 0x00, 0x41, 0x7F, 0x7F, 0x41, 0x00, 0x00,    // Char 073 (I)
        0x00, 0x20, 0x60, 0x41, 0x7F, 0x3F, 0x01, 0x00,    // Char 074 (J)
        0x00, 0x7F, 0x7F, 0x1C, 0x36, 0x63, 0x41, 0x00,    // Char 075 (K)
        0x00, 0x7F, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x00,    // Char 076 (L)
        0x00, 0x7F, 0x7F, 0x06, 0x0C, 0x06, 0x7F, 0x7F,    // Char 077 (M)
        0x00, 0x7F, 0x7F, 0x0E, 0x1C, 0x7F, 0x7F, 0x00,    // Char 078 (N)
        0x00, 0x3E, 0x7F, 0x41, 0x41, 0x7F, 0x3E, 0x00,    // Char 079 (O)
        0x00, 0x7F, 0x7F, 0x09, 0x09, 0x0F, 0x06, 0x00,    // Char 080 (P)
        0x00, 0x1E, 0x3F, 0x21, 0x61, 0x7F, 0x5E, 0x00,    // Char 081 (Q)
        0x00, 0x7F, 0x7F, 0x19, 0x39, 0x6F, 0x46, 0x00,    // Char 082 (R)
        0x00, 0x26, 0x6F, 0x49, 0x49, 0x7B, 0x32, 0x00,    // Char 083 (S)
        0x00, 0x01, 0x01, 0x7F, 0x7F, 0x01, 0x01, 0x00,    // Char 084 (T)
        0x00, 0x3F, 0x7F, 0x40, 0x40, 0x7F, 0x3F, 0x00,    // Char 085 (U)
        0x00, 0x1F, 0x3F, 0x60, 0x60, 0x3F, 0x1F, 0x00,    // Char 086 (V)
        0x00, 0x7F, 0x7F, 0x30, 0x18, 0x30, 0x7F, 0x7F,    // Char 087 (W)
        0x00, 0x63, 0x77, 0x1C, 0x1C, 0x77, 0x63, 0x00,    // Char 088 (X)
        0x00, 0x07, 0x0F, 0x78, 0x78, 0x0F, 0x07, 0x00,    // Char 089 (Y)
        0x00, 0x61, 0x71, 0x59, 0x4D, 0x47, 0x43, 0x00,    // Char 090 (Z)
        0x18, 0x18, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0x18,    // Char 091 ([)
        0x33, 0x33, 0xCC, 0xCC, 0x00, 0x00, 0x00, 0x00,    // Char 092 (\)
        0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,    // Char 093 (])
        0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00,    // Char 094 (^)
        0x00, 0x00, 0x00, 0xF0, 0xF0, 0x00, 0x00, 0x00,    // Char 095 (_)
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,    // Char 096 (`)
        0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,    // Char 097 (a)
        0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,    // Char 098 (b)
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,    // Char 099 (c)
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,    // Char 100 (d)
        0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    // Char 101 (e)
        0x33, 0x33, 0xCC, 0xCC, 0x33, 0x33, 0xCC, 0xCC,    // Char 102 (f)
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,    // Char 103 (g)
        0x30, 0x30, 0xC0, 0xC0, 0x30, 0x30, 0xC0, 0xC0,    // Char 104 (h)
        0x33, 0x99, 0xCC, 0x66, 0x33, 0x99, 0xCC, 0x66,    // Char 105 (i)
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,    // Char 106 (j)
        0x00, 0x00, 0x00, 0xFF, 0xFF, 0x18, 0x18, 0x18,    // Char 107 (k)
        0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0xF0,    // Char 108 (l)
        0x00, 0x00, 0x00, 0x1F, 0x1F, 0x18, 0x18, 0x18,    // Char 109 (m)
        0x18, 0x18, 0x18, 0xF8, 0xF8, 0x00, 0x00, 0x00,    // Char 110 (n)
        0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,    // Char 111 (o)
        0x00, 0x00, 0x00, 0xF8, 0xF8, 0x18, 0x18, 0x18,    // Char 112 (p)
        0x18, 0x18, 0x18, 0x1F, 0x1F, 0x18, 0x18, 0x18,    // Char 113 (q)
        0x18, 0x18, 0x18, 0xF8, 0xF8, 0x18, 0x18, 0x18,    // Char 114 (r)
        0x18, 0x18, 0x18, 0xFF, 0xFF, 0x00, 0x00, 0x00,    // Char 115 (s)
        0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    // Char 116 (t)
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,    // Char 117 (u)
        0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,    // Char 118 (v)
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,    // Char 119 (w)
        0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,    // Char 120 (x)
        0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,    // Char 121 (y)
        0x00, 0x78, 0x78, 0x30, 0x18, 0x0C, 0x06, 0x03,    // Char 122 (z)
        0xF0, 0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00,    // Char 123 ({)
        0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F,    // Char 124 (|)
        0x18, 0x18, 0x18, 0x1F, 0x1F, 0x00, 0x00, 0x00,    // Char 125 (})
        0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00,    // Char 126 (~)
        0x0F, 0x0F, 0x0F, 0x0F, 0xF0, 0xF0, 0xF0, 0xF0
};

#endif

#define CHAR_PTR(c) (font + (c)*FONT_WIDTH)

#endif        /* __LCD_FONT_H */

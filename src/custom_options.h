//
// Created by Flynn on 17.04.2024.
//

#ifdef MONO_U8G2

// Define u8g2 plugin params
#ifndef MONO_U8G2_DISPLAY
#define MONO_U8G2_DISPLAY U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI
#endif

#ifndef RENDERER_PAGE_BUFFER
#define RENDERER_PAGE_BUFFER
#endif

#ifndef DISPLAY_WIDTH
#define DISPLAY_WIDTH 128
#endif

#ifndef DISPLAY_HEIGHT
#define DISPLAY_HEIGHT 64
#endif

#ifndef U8G2_PINS
#define DISPLAY_CS 15
#define DISPLAY_DC 2
#define DISPLAY_RESET 16
#define U8G2_PINS U8G2_R0, DISPLAY_CS, DISPLAY_DC, DISPLAY_RESET
#endif

#endif


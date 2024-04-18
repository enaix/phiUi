//
// Created by Flynn on 17.04.2024.
//

// Global options
// ==============
#ifndef DISPLAY_WIDTH
#define DISPLAY_WIDTH 128
#endif

#ifndef DISPLAY_HEIGHT
#define DISPLAY_HEIGHT 64
#endif


// U8G2-specific options
// =====================
#ifdef MONO_U8G2

// u8g2 display type
#ifndef MONO_U8G2_DISPLAY
#define MONO_U8G2_DISPLAY U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI
#endif

// Enable page buffer mode for u8g2
#ifndef RENDERER_PAGE_BUFFER
#define RENDERER_PAGE_BUFFER
#endif

// Display pins (u8g2 configuration)
#ifndef U8G2_PINS
#define DISPLAY_CS 15
#define DISPLAY_DC 2
#define DISPLAY_RESET 16
#define U8G2_PINS U8G2_R0, DISPLAY_CS, DISPLAY_DC, DISPLAY_RESET
#endif

#endif


// Desktop-specific options
// ========================
#ifdef DESKTOP

#ifndef MONOCHROME
#define MONOCHROME
#endif

// Desktop scaling factor
#ifndef DESKTOP_SCALING
#define DESKTOP_SCALING 5
#endif

#endif


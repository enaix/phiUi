//
// Created by Flynn on 24.02.2024.
//

#ifndef PHIUI_OPTIONS_H
#define PHIUI_OPTIONS_H

// Defining default compilation options and conditional stuff


// ARRAYS MEMORY PARAMETERS
// ========================

// Default array growth multiplier
#ifndef ARRAY_RESERVE
#define ARRAY_RESERVE 2
#endif

// Small array preallocation size
#ifndef ARRAY_PREALLOC_SMALL
#define ARRAY_PREALLOC_SMALL ARRAY_RESERVE
#endif

// Large array preallocation size
#ifndef ARRAY_PREALLOC_LARGE
#define ARRAY_PREALLOC_LARGE 10
#endif


// INLINE METHODS PARAMS
// =====================

// Minimal flash size increase, high performance gain. Pass INLINE_SM_DISABLE flag to disable
#ifndef INLINE_SM_DISABLE
#define INLINE_SM inline
#endif


// GENERATED PARAMETERS
// ====================

// Defining the renderer type
#if defined(MONO_U8G2)

#ifndef MONO_U8G2_DISPLAY  // Check for the display type, it must be defined
#error "MONO_U8G2_DISPLAY is unset. Please define the display type"
#endif

#ifndef MONOCHROME
#define MONOCHROME // Set color to monochrome
#endif

#elif defined(DESKTOP)

#ifndef DISPLAY_WIDTH
#error "DISPLAY_WIDTH is unset. Please define display width to emulate"
#endif

#ifndef DISPLAY_HEIGHT
#error "DISPLAY_HEIGHT is unset. Please define display width to emulate"
#endif

#ifndef RENDERER_TYPE
class Desktop;
// Define the renderer type
#define RENDERER_TYPE Desktop
#endif

#else

#error "No framework has been selected. Please define renderer macro"

#endif

#endif //PHIUI_OPTIONS_H

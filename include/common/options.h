//
// Created by Flynn on 24.02.2024.
//

#ifndef PHIUI_OPTIONS_H
#define PHIUI_OPTIONS_H

// Defining default compilation options

// Arrays memory parameters
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

#endif //PHIUI_OPTIONS_H

//
// Created by Flynn on 01.04.2024.
//

#ifndef PHIUI_RENDERER_H
#define PHIUI_RENDERER_H

// Include the correct renderer

#if defined(MONO_U8G2)
// Include u8g2 renderer
#elif defined(DESKTOP)

#include "renderer/desktop.h"

#endif

#endif //PHIUI_RENDERER_H

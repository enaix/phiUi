//
// Created by Flynn on 01.04.2024.
//

#ifndef PHIUI_RENDERER_H
#define PHIUI_RENDERER_H

// Include the correct renderer

#if defined(MONO_U8G2)

#include "renderer/u8g2_plugin.h"

#elif defined(DESKTOP)

#include "renderer/desktop.h"

#endif

#endif //PHIUI_RENDERER_H

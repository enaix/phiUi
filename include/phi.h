//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_PHI_H
#define PHIUI_PHI_H

#ifdef MONO_U8G2  // Enable monochrome U8G2 plugin

#ifndef MONO_U8G2_DISPLAY  // Check for the display type, it must be defined
#error "MONO_U8G2_DISPLAY is unset. Please define the display type"
#endif

#define MONOCHROME // Set color to monochrome

#include <U8g2lib.h>

#elif defined(DESKTOP)

#ifndef DISPLAY_WIDTH
#error "DISPLAY_WIDTH is unset. Please define display width to emulate"
#endif

#ifndef DISPLAY_HEIGHT
#error "DISPLAY_HEIGHT is unset. Please define display width to emulate"
#endif

#include "renderer/desktop.h"

#else

#error "No framework has been selected. Please define renderer macro"

#endif

#include "common/common.h"

namespace phi
{

    class Phi
    {
    public:
#ifdef MONO_U8G2
        Phi(MONO_U8G2_DISPLAY display);
#endif
#ifdef DESKTOP
        Phi();
#endif

#ifdef MONO_U8G2
        MONO_U8G2_DISPLAY u8g2;
#endif

#ifdef DESKTOP
        Desktop renderer;
#endif
        void loop();
    };

} // phi

#endif //PHIUI_PHI_H

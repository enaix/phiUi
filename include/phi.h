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
#include "widgets/widgets.h"
#include "state/state.h"

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
        // TODO move display declaration to renderer
#endif

#ifdef DESKTOP
        RENDERER_TYPE renderer;
#endif
        void loop();

        void set_root(Screen* root);

        void show();

    protected:
        State _state;
    };

} // phi

#endif //PHIUI_PHI_H

//
// Created by Flynn on 23.01.2024.
//

#include "phi.h"

namespace phi
{
#ifdef MONO_U8G2
    Phi::Phi(MONO_U8G2_DISPLAY display) : u8g2(display)
    {}
#endif

#ifdef DESKTOP
    Phi::Phi() : renderer({DISPLAY_WIDTH, DISPLAY_HEIGHT})
    {}
#endif

    void Phi::loop()
    {
#ifdef DESKTOP
        renderer.clear();
        // Call the skin to redraw
        renderer.render();
#endif
    }
} // phi
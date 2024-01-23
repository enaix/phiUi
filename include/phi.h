//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_PHI_H
#define PHIUI_PHI_H

#ifdef MONO_U8G2  // Enable monochrome U8G2 plugin

#ifndef MONO_U8G2_DISPLAY  // Check for the display type, it must be defined
#error "MONO_U8G2_DISPLAY is unset. Please define the display type"
#endif

#include <U8g2lib.h>

#endif  // MONO_U8G2

namespace phi
{

    class Phi
    {
    public:
#ifdef MONO_U8G2
        Phi(MONO_U8G2_DISPLAY display);
#endif
    protected:
#ifdef MONO_U8G2
        MONO_U8G2_DISPLAY u8g2;
#endif
    };

} // phi

#endif //PHIUI_PHI_H

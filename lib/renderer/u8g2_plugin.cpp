//
// Created by Flynn on 16.04.2024.
//

#include "phi_options.h"

#ifdef MONO_U8G2

#include "u8g2_plugin.h"

namespace phi
{
    U8G2Plugin::U8G2Plugin(Point res) : Renderer(res), u8g2(U8G2_PINS)
    {
        u8g2.begin();
    }

} // phi

#endif //MONO_U8G2
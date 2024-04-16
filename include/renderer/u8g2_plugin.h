//
// Created by Flynn on 16.04.2024.
//

#ifdef MONO_U8G2

#ifndef PHIUI_U8G2_PLUGIN_H
#define PHIUI_U8G2_PLUGIN_H

#include "common/options.h"
#include "common/common.h"
#include "renderer/renderer_base.h"

#include <U8g2lib.h>

namespace phi
{

    class U8G2Plugin : public Renderer
    {
    public:
        explicit U8G2Plugin(Point res);

        INLINE_SM void drawPixel(Point pos);
        INLINE_SM void drawFilledRect(Point pos, Size size);
        INLINE_SM void drawRect(Point pos, Size size);
        INLINE_SM void setColor(Color color);
        INLINE_SM bool render();
        inline void poll();
        INLINE_SM void clear();

    protected:
        MONO_U8G2_DISPLAY u8g2;
    };

} // phi

#endif //PHIUI_U8G2_PLUGIN_H

#endif //MONO_U8G2

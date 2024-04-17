//
// Created by Flynn on 16.04.2024.
//

#include "phi_options.h"

#ifdef MONO_U8G2

#ifndef PHIUI_U8G2_PLUGIN_H
#define PHIUI_U8G2_PLUGIN_H

#include "phi_common.h"
#include "renderer_base.h"

#include "U8g2lib.h"

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

    INLINE_SM void U8G2Plugin::clear()
    {
#ifdef RENDERER_PAGE_BUFFER
        u8g2.firstPage();
#else
        u8g2.clearBuffer();
#endif
    }

    INLINE_SM bool U8G2Plugin::render()
    {
#ifdef RENDERER_PAGE_BUFFER
        // Here we return true to render again (in page mode)
        return u8g2.nextPage();
#else
        u8g2.sendBuffer();
        return true;
#endif
    }

    inline void U8G2Plugin::poll()
    {

    }

    INLINE_SM void U8G2Plugin::drawPixel(Point pos)
    {
        u8g2.drawPixel(pos.x, pos.y);
    }

    INLINE_SM void U8G2Plugin::drawRect(Point pos, Size size)
    {
        u8g2.drawFrame(pos.x, pos.y, size.width, size.height);
    }

    INLINE_SM void U8G2Plugin::drawFilledRect(Point pos, Size size)
    {
        u8g2.drawBox(pos.x, pos.y, size.width, size.height);
    }

    INLINE_SM void U8G2Plugin::setColor(Color color)
    {
#ifdef MONOCHROME
        u8g2.setDrawColor(color.color);
#else
#error "U8G2 cannot work with non-monochrome displays"
#endif
    }

} // phi

#endif //PHIUI_U8G2_PLUGIN_H

#endif //MONO_U8G2

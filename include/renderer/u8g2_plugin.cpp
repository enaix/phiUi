//
// Created by Flynn on 16.04.2024.
//

#ifdef MONO_U8G2

#include "renderer/u8g2_plugin.h"

namespace phi
{
    U8G2Plugin::U8G2Plugin(Point res) : Renderer(res), u8g2(U8G2_PINS)
    {
        u8g2.begin();
    }

    void U8G2Plugin::clear()
    {
#if RENDERER_PAGE_BUFFER
        u8g2.firstPage();
#else
        u8g2.clearBuffer();
#endif
    }

    bool U8G2Plugin::render()
    {
#if RENDERER_PAGE_BUFFER
        // Here we return true to render again (in page mode)
        return u8g2.nextPage();
#else
        u8g2.sendBuffer();
        return true;
#endif
    }

    void U8G2Plugin::poll()
    {

    }

    void U8G2Plugin::drawPixel(Point pos)
    {
        u8g2.drawPixel(pos.x, pos.y);
    }

    void U8G2Plugin::drawRect(Point pos, Size size)
    {
        u8g2.drawFrame(pos.x, pos.y, size.width, size.height);
    }

    void U8G2Plugin::drawFilledRect(Point pos, Size size)
    {
        u8g2.drawBox(pos.x, pos.y, size.width, size.height);
    }

    void U8G2Plugin::setColor(Color color)
    {
#ifdef MONOCHROME
        u8g2.setDrawColor(color.color);
#else
#error "U8G2 cannot work with non-monochrome displays"
#endif
    }
} // phi

#endif //MONO_U8G2
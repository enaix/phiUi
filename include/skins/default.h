//
// Created by Flynn on 26.01.2024.
//

#ifndef PHIUI_DEFAULT_H
#define PHIUI_DEFAULT_H

#include "common/common.h"
#include "widgets/widgets.h"
#include "skins/skins_common.h"

namespace phi
{
    DRAW_COUNTER_START

    class Skin
    {
    public:
        template<class Wid>
        requires WidgetType<Wid, "BaseWidget">
        static void draw(Wid* wid, RENDERER_TYPE* renderer) // Draw default widget
        {
            renderer->drawRect(wid->pos, wid->size);
        }

        template<class Wid>
        requires WidgetType<Wid, "BaseScreen">
        static void draw(Wid* wid, RENDERER_TYPE* renderer) // Draw default screen
        {
            renderer->drawRect(wid->pos, wid->size);
        }

        template<class Wid>
        requires WidgetType<Wid, "None">
        __attribute__ ((warning ("Could not find skin overload")))
        static void draw(Wid* wid, RENDERER_TYPE* renderer)
        {
            // Do nothing;
        }
    };


} // phi

#endif //PHIUI_DEFAULT_H

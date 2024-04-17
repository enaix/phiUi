//
// Created by Flynn on 26.01.2024.
//

#ifndef PHIUI_DEFAULT_H
#define PHIUI_DEFAULT_H

#include "phi_common.h"
#include "widgets.h"
#include "skins_common.h"

namespace phi
{
    class Skin
    {
    public:
        template<WidType<"BaseWidget"> type, class Wid>
        void draw(Wid* wid, RENDERER_TYPE* renderer) // Draw default widget
        {
            renderer->drawRect(wid->pos, wid->size);
        }

        template<WidType<"BaseScreen"> type, class Wid>
        void draw(Wid* wid, RENDERER_TYPE* renderer) // Draw default screen
        {
            renderer->drawRect(wid->pos, wid->size);
        }

        template<WidType<"None"> type, class Wid>
        __attribute__ ((warning ("Could not find skin overload")))
        void draw(Wid* wid, RENDERER_TYPE* renderer)
        {
            // Do nothing;
        }

        template<WidName<"BiosBox"> type, class Wid>
        void draw(Wid* wid, RENDERER_TYPE* renderer) // Draw default screen
        {
            renderer->drawRect(wid->pos, wid->size);
            renderer->drawRect({i16(wid->pos.x+1), i16(wid->pos.y+1)}, wid->size);
        }
    };


} // phi

#endif //PHIUI_DEFAULT_H

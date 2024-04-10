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
    };


} // phi

#endif //PHIUI_DEFAULT_H

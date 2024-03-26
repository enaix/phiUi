//
// Created by Flynn on 26.01.2024.
//

#ifndef PHIUI_DEFAULT_H
#define PHIUI_DEFAULT_H

#include "common/common.h"
#include "widgets/widgets.h"

namespace phi
{

    template<class Wid>
    void paint_widget_box(Wid wid, RENDERER_TYPE renderer)
    {
        renderer.drawRect(wid.pos, wid.size);
    }

} // phi

#endif //PHIUI_DEFAULT_H

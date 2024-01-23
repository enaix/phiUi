//
// Created by Flynn on 23.01.2024.
//

#include "widgets.h"

namespace phi
{

    Widget::Widget(Screen* parent, Point pos = {0, 0}, Size size = {0, 0}, Flag extra_flags = 0)
    : Base(), parent(parent), pos(pos), size(size)
    {
        flags ^= extra_flags;
    }

} // phi
//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_WIDGETS_H
#define PHIUI_WIDGETS_H

#include "common/common.h"

namespace phi
{

    class Screen;

    class Widget : public Base
    {
    public:
        Widget(Screen* parent, Point pos, Size size, Flag extra_flags);

        Screen* parent;
        Point pos;
        Size size;  // TODO implement size policy
        Size bg_size;
        ui8 margin;
        // Flags flags;  <- they are in the derived class
    };

    class Spacer : public Base
    {
    public:
        Spacer() : Base() {};
        Flag flags = Flag(WidgetFlags::Hidden) | Flag(WidgetFlags::Spacer);
    };

    class Screen : public Widget
    {
    public:
        Screen();
        ~Screen();
        void (*init)();
        void (*die)();

        Base* widgets;
        Selector select;
        Flag screen_flags;
        Flag screen_policy;
        ui8 padding;
    };

} // phi

#endif //PHIUI_WIDGETS_H

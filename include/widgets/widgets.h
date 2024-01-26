//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_WIDGETS_H
#define PHIUI_WIDGETS_H

#include "common/common.h"
#include "common/containers.h"

namespace phi
{

    class Screen;

    class Widget : public Base
    {
    public:
        Widget(Screen* parent, Point pos, Size size, Flag extra_flags, Flag size_flags);

        Screen* parent;
        Point pos;
        Size size;  // TODO implement size policy
        Size bg_size;
        Margin margin;
        // Flags flags;  <- they are in the derived class
        Flag size_flags;
    };

    class Screen : public Widget
    {
    public:
        Screen(Screen* parent, Point pos, Size size, Flag extra_flags, Flag extra_size_policy, Flag extra_screen_flags,
               Flag screen_policy);
        ~Screen();
        void (*init)();
        void compute_widget_sizes();

        Array<Base*> widgets;
        Selector select;
        Flag screen_flags;
        Flag screen_policy;
        ui8 padding;
    protected:
        void _constraint_process(bool is_vertical);
    };

    class Wrapper : public Screen
    {
    public:
        Wrapper();
    };

} // phi

#endif //PHIUI_WIDGETS_H

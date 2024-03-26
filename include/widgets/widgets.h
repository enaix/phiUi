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
    class State;

    class Widget : public Base
    {
    public:
        Widget(Screen* parent, SizeHint hint, Point pos, Size size, Flag extra_flags, Flag size_flags);

        Screen* parent;
        Point pos;
        Size size;  // TODO implement size policy
        Size bg_size;
        Margin margin;
        // Flags flags;  <- they are in the derived class
        Flag size_flags;
        SizeHint size_hint;
        Array<void(*)(Widget, RENDERER_TYPE)> classes;
    };

    class Screen : public Widget
    {
    public:
        Screen(Screen* parent, SizeHint hint, Point pos, Size size, Flag extra_flags, Flag extra_size_policy, Flag extra_screen_flags,
               Flag screen_policy);
        ~Screen() {};
        void (*init)();
        void constraint();

        Array<Base*> widgets;
        Selector select;
        Flag screen_flags;
        Flag screen_policy;
        Padding padding;

        friend State;
    protected:
        bool is_init;
        template<bool is_vertical>
        void _constraint_process();
        template<bool is_vertical>
        INLINE_SM ui16 _margin_process(Widget* wid, Point topleft, Point bottomright, bool& expanding);
    };

    class Wrapper : public Screen
    {
    public:
        Wrapper();
    };

} // phi

#endif //PHIUI_WIDGETS_H

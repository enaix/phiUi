//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_WIDGETS_H
#define PHIUI_WIDGETS_H

#include "common/common.h"
#include "common/containers.h"
#include "renderer/renderer.h"
#include "skins/skins_common.h"

namespace phi
{

    class Screen;
    class State;

    class Widget : public Base
    {
    public:
        explicit Widget(Screen* parent, SizeHint hint = {1, 1}, Point pos = {0, 0}, Size size = {0, 0}, Flag extra_flags = 0,
               Flag size_flags = 0);

        Screen* parent;
        Point pos;
        Size size;  // TODO implement size policy
        Size bg_size;
        Margin margin;
        // Flags flags;  <- they are in the derived class
        Flag size_flags;
        SizeHint size_hint;

        // Define default type and name
        WID_TYPE("BaseWidget")
        WID_NAME("")
    };

    class Screen : public Widget
    {
    public:
        explicit Screen(Screen* parent, SizeHint hint = {1, 1}, Point pos = {0, 0}, Size size = {0, 0}, Flag extra_flags = 0,
               Flag extra_size_flags = 0, Flag extra_screen_flags = 0, Flag screen_policy = 0);
        ~Screen() {};
        void (*init)(Screen*);
        void constraint();

        Array<Widget> widgets;
        Selector select;
        Flag screen_flags;
        Flag screen_policy;
        Padding padding;

        WID_TYPE("BaseScreen")
        WID_NAME("")
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

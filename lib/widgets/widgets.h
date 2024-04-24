//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_WIDGETS_H
#define PHIUI_WIDGETS_H

#include "phi_common.h"
#include "phi_containers.h"
#include "phi_renderer.h"
#include "skins_common.h"

namespace phi
{

    class Screen;
    class State;
    class Skin;

    class Widget : public Base
    {
    public:
        template<st N>
        constexpr Widget(const char (&elem_name)[N]) : Base(), parent(nullptr), pos({0, 0}), size({0, 0}), size_flags(0), margin({0, 0, 0, 0}),
        size_hint({1, 1}), bg_size({0, 0}), draw(nullptr)
        {
            //std::copy_n(elem_name, N, name);
            flags = 0;
        }

        explicit Widget(Screen* parent, SizeHint hint = {1, 1}, Point pos = {0, 0}, Size size = {0, 0}, Flag extra_flags = 0,
               Flag size_flags = 0);


        void (*draw)(Skin*, Widget*, RENDERER_TYPE*);
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
    };

    class Screen : public Widget
    {
    public:
        template<st N>
        constexpr Screen(const char (&elem_name)[N]) : Widget(elem_name), init(nullptr), widgets(), select(0), padding({0, 0, 0, 0}),
        screen_flags(0), screen_policy(0), is_init(false)
        {
        }

        explicit Screen(Screen* parent, SizeHint hint = {1, 1}, Point pos = {0, 0}, Size size = {0, 0}, Flag extra_flags = 0,
               Flag extra_size_flags = 0, Flag extra_screen_flags = 0, Flag screen_policy = 0);
        ~Screen() {};
        void (*init)(Screen*, State*);
        void constraint();

        Array<Widget> widgets;
        Selector select;
        Flag screen_flags;
        Flag screen_policy;
        Padding padding;

        WID_TYPE("BaseScreen")
        //WID_NAME
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

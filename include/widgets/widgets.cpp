//
// Created by Flynn on 23.01.2024.
//

#include "widgets.h"

namespace phi
{

    Widget::Widget(Screen* parent, SizeHint hint = {1, 1}, Point pos = {0, 0}, Size size = {0, 0}, Flag extra_flags = 0,
                   Flag size_flags = 0)
    : Base(), parent(parent), pos(pos), size(size), size_flags(size_flags), margin({0, 0, 0, 0}),
      size_hint(hint)
    {
        flags ^= extra_flags;
    }

    Screen::Screen(Screen* parent, SizeHint hint = {1, 1}, Point pos = {0, 0}, Size size = {0, 0}, Flag extra_flags = 0,
                   Flag extra_size_flags = 0, Flag extra_screen_flags = 0, Flag screen_policy = 0)
    : Widget(parent, hint, pos, size, extra_flags), init(nullptr), widgets(), select(0), padding({0, 0, 0, 0}),
    screen_flags(extra_screen_flags), screen_policy(screen_policy)
    {
        size_flags = extra_size_flags;
    }

    void Screen::constraint()
    {
        if (widgets.size() == 0)
        {
            // No widgets to handle
            return;
        }

        switch (ScreenPolicy(screen_policy))
        {
            case ScreenPolicy::Vertical:
                _constraint_process<true>();
                break;
            case ScreenPolicy::Horizontal:
                _constraint_process<false>();
                break;
            case ScreenPolicy::Grid:
                break;
            default:
                // Handle widget sizes as is

                break;
        }
    }

    template<bool is_vertical>
    void Screen::_constraint_process()
    {
        ui16 total_size = 0;

        // In order to save memory, we iterate over the list twice O(2*n)
        for (st i = 0; i < widgets.size(); i++)
        {
            if (has_flag(widgets[i]->flags, WidgetFlags::Hidden))
                continue;

            // Here we can safely cast this to Widget*
            Widget* wid = static_cast<Widget*>(widgets[i]);

            if (has_flag(wid->size_flags, SizeFlags::Fixed))
                continue;

            /* Handle margin + padding, perhaps in a separate function
               We have both margin: auto and align
               Margin works by expanding, align is a hint and doesn't expand out of the limits */

            bool expanding = false;
            ui16 wid_ts;

            // TODO perhaps we should somehow calculate bottomright differently
            if constexpr(is_vertical)
            {
                wid_ts = _margin_process<true>(wid, {0, i16(total_size)}, {i16(size.width), i16(size.height)},
                                         expanding);
            }
            else
            {
                wid_ts = _margin_process<false>(wid, {i16(total_size), 0}, {i16(size.width), i16(size.height)},
                                         expanding);
            }
            total_size += wid_ts;
            // TODO process padding: auto and other expanding stuff
        }
    }

    template<bool is_vertical>
    INLINE_SM ui16 Screen::_margin_process(Widget* wid, Point topleft, Point bottomright, bool& expanding)
    {
        // This function calculates widget position and size based on its margin and align in the given rectangle
        // We return the size taken by the widget

        ui16 total_size = 0;
        i16 wid_pos_x, wid_pos_y;

        if constexpr(is_vertical)
        {
            // Topleft
            wid_pos_x = wid->margin.left + padding.left;
            wid_pos_y = wid->margin.top + padding.top + topleft.y;
        }
        // TODO add padding: auto
        else
        {
            // Topleft
            wid_pos_x = wid->margin.left + padding.left + topleft.x;
            wid_pos_y = wid->margin.top + padding.top;
        }

        if (!has_flag(wid->size_flags, SizeFlags::MinHeight))
        {
            // Widget height is relative to parent
            wid->size.height = wid->size_hint.h * this->size.height / 12;
            // TODO think about 12 as a constant
        } // else .height contains exact height

        if (!has_flag(wid->size_flags, SizeFlags::MinWidth))
        {
            // Widget height is relative to parent
            wid->size.width = wid->size_hint.w * this->size.width / 12;
        }

        wid->pos.x = wid_pos_x;
        wid->pos.y = wid_pos_y;
        // TODO perhaps add expanding padding

        if constexpr (is_vertical)
            return wid->size.height + wid->margin.bottom;
        else
            return wid->size.width + wid->margin.right;


    }

} // phi
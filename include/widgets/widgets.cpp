//
// Created by Flynn on 23.01.2024.
//

#include "widgets.h"

namespace phi
{

    Widget::Widget(Screen* parent, Point pos = {0, 0}, Size size = {0, 0}, Flag extra_flags = 0,
                   Flag size_flags = 0)
    : Base(), parent(parent), pos(pos), size(size), size_flags(size_flags), margin({0, 0, 0, 0})
    {
        flags ^= extra_flags;
    }

    Screen::Screen(Screen* parent, Point pos = {0, 0}, Size size = {0, 0}, Flag extra_flags = 0,
                   Flag extra_size_flags = 0, Flag extra_screen_flags = 0, Flag screen_policy = 0)
    : Widget(parent, pos, size, extra_flags), init(nullptr), widgets(), select(0), padding({0, 0, 0, 0}),
    screen_flags(extra_screen_flags), screen_policy(screen_policy)
    {
        size_flags = (Flag(SizeFlags::VExpanding) | Flag(SizeFlags::HExpanding)) ^ extra_size_flags;
    }

    void Screen::compute_widget_sizes()
    {
        if (widgets.size() == 0)
        {
            // No widgets to handle
            return;
        }

        switch (ScreenPolicy(screen_policy))
        {
            case ScreenPolicy::Vertical:
                _constraint_process(true);
                break;
            case ScreenPolicy::Horizontal:
                _constraint_process(false);
                break;
            case ScreenPolicy::Grid:
                break;
            default:
                // Handle widget sizes as is

                break;
        }
    }

    void Screen::_constraint_process(bool is_vertical)
    {
        ui16 total_size = 0;

        st expanding_wid = 0;

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

            if (has_flag(wid->size_flags, SizeFlags::VExpanding))
            {
                if (is_vertical)
                {
                    expanding_wid++;
                    // We need to handle the size and margin + padding later
                }
                else
                {
                    // The widget must fill the whole cell
                    wid->pos.y = pos.y;
                    wid->pos.x = total_size;
                    // Calculate margin (margin: auto won't do anything here)
                }
            }
        }
    }

    ui16 Screen::_margin_process(Widget* wid, Point topleft, Point bottomright, bool vertical, bool& expanding)
    {
        if (wid->margin.top == margin_auto && wid->margin.bottom == margin_auto && !vertical)
        {
            // Center
            // TODO calculate center
        }

        // same for other align options

        if ((wid->margin.top == margin_auto || wid->margin.bottom == margin_auto) && vertical ||
                (wid->margin.left == margin_auto || wid->margin.right == margin_auto) && !vertical)
        {
            // We need to calculate margin in the end
            expanding = true;
            return 0;
        }
    }

} // phi
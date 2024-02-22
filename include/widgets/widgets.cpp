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

            bool expanding = false;
            ui16 wid_ts;

            // TODO perhaps we should somehow calculate bottomright differently
            if (is_vertical)
            {
                wid_ts = _margin_process(wid, {0, i16(total_size)}, {i16(size.width), i16(size.height)}, is_vertical,
                                         expanding);
            }
            else
            {
                wid_ts = _margin_process(wid, {i16(total_size), 0}, {i16(size.width), i16(size.height)}, is_vertical,
                                         expanding);
            }

            if (expanding)
            {
                expanding_wid++;
                // We need to handle the size and margin + padding later
            }
        }
    }

    ui16 Screen::_margin_process(Widget* wid, Point topleft, Point bottomright, bool vertical, bool& expanding)
    {
        // This function calculates widget position and size based on its margin and align in the given rectangle
        // We return the size taken by the widget

        ui16 total_size = 0;

        if (!vertical && (wid->margin.top == margin_auto || has_flag(wid->size_flags, SizeFlags::AlignVCenter)))
        {
            // Center (vertical in HBox)
            i16 wid_pos = wid->margin.top + padding.top;
            ui16 wid_size, max_size = bottomright.y - topleft.y - wid->margin.bottom - padding.bottom - wid_pos;
            if (has_flag(wid->size_flags, SizeFlags::VExpanding))
            {
                wid_size = max_size;
                wid->size.height = wid_size;
            }
            else
            {
                wid_size = wid->size.height;
                wid_pos += (max_size - wid_size) / 2;
                // TODO perhaps we need align here
            }
            wid->pos.y = wid_pos;
        }

        // Perhaps this should be in a separate macro function
        else if (vertical && (wid->margin.left == margin_auto || has_flag(wid->size_flags, SizeFlags::AlignHCenter)))
        {
            // Center (horizontal in VBox)
            i16 wid_pos = wid->margin.left + padding.left;
            ui16 wid_size, max_size = bottomright.x - topleft.x - wid->margin.right - padding.right - wid_pos;
            if (expanding)
            {
                wid_size = max_size;
                wid->size.height = wid_size;
            }
            else
            {
                wid_size = wid->size.width;
                wid_pos += (max_size - wid_size) / 2;
                // TODO ditto
            }
            wid->pos.y = wid_pos;
        }

        // Here we handle regular margin options
        if (wid->margin.top != margin_auto)
        {
            i16 wid_pos = wid->margin.top + padding.top;
            wid->pos.y = wid_pos;

            // TODO perhaps handle alignment here (or in a second pass)

            if (vertical)
                total_size += wid_pos + wid->size.height + wid->margin.bottom + padding.bottom;
        }

        if (wid->margin.left != margin_auto)
        {
            i16 wid_pos = wid->margin.left + padding.left;
            wid->pos.x = wid_pos;

            if (!vertical)
                total_size += wid_pos + wid->size.width + wid->margin.right + padding.right;
        }

        wid->pos += topleft;

        if (wid->margin.top == margin_auto && vertical || wid->margin.left == margin_auto && !vertical)
        {
            // We need to calculate margin in the end
            expanding = true;
            return 0;
        }

        return total_size;
    }

} // phi
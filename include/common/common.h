//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_COMMON_H
#define PHIUI_COMMON_H

#include "options.h"
#include "skins/skins_common.h"

#include <cstdint>
#include <climits>

namespace phi
{

    // Size constants, may be overloaded in some cases (large screens)
    typedef int8_t i8;
    typedef int16_t i16;
    typedef int32_t i32;
    typedef uint8_t ui8;
    typedef uint16_t ui16;
    typedef uint32_t ui32;

    typedef ui8 Flag;  // There should be enough space for 8 flags
    typedef ui16 st;  // size_t

#ifdef INCREASE_WIDGETS_LIMIT
    typedef ui16 Selector;  // 65536 elements is maximum
#else
    typedef ui8 Selector;  // 256 elements is maximum
#endif

#ifdef INCREASE_MARGIN_LIMIT
    typedef ui16 ms;  // 65536 units max (4*2=8 bytes for each widget)
    #define margin_auto 65535
#else
    typedef ui8 ms;  // 256 units max (4 bytes for each widget)
    #define margin_auto 255
#endif

    struct Point
    {
        i16 x;
        i16 y;
        Point& operator+=(const Point& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }
    };

    struct Size
    {
        ui16 width;
        ui16 height;
    };

    // Maximum value of margin is treated as auto
    // Auto margin can only be applied to both left+right or top+bottom
    struct Margin
    {
        ms left;
        ms top;
        ms right;
        ms bottom;
    };

    // Set an alias to padding
    typedef Margin Padding;

    struct SizeHint
    {
        ui8 w;
        ui8 h;
    };

    enum class WidgetFlags : Flag
    {
        Disabled = 0b1,  // Cannot select widget, is rendered differently
        Unselectable = 0b10,  // This widget won't be selected
        Hidden = 0b100,  // This widget is not rendered at all
        // Spacer = 0b1000,  // This is a spacer expanding item
    };

    enum class SizeFlags : Flag
    {
        Fixed = 0b1,  // Set fixed widget position
        MinWidth = 0b10,  // Fixed widget size
        MinHeight = 0b100,  // ditto
        AlignLeft = 0b1000,  // Align to the left, ignore position
        AlignRight = 0b10000,  // Align to the right, ignore position
        AlignTop = 0b100000,  // Align to the top, ignore position
        AlignBottom = 0b1000000,  // Align to the bottom, ignore position
        AlignVCenter = AlignTop | AlignBottom,  // Align to the vertical center
        AlignHCenter = AlignLeft | AlignRight,  // Align to the horizontal center
    };

    enum class ScreenFlags : Flag
    {
        Overlay = 0b1,  // This screen is a global overlay
        Opaque = 0b10,  // Screen background is translucent; TODO check how u8g2 handles this,
        Wrapper = 0b100,  // This screen is a wrapper object
    };

    enum class ScreenPolicy : Flag
    {
        // Fixed,  // Default behavior
        Vertical,
        Horizontal,
        Grid
    };

    enum class RendererFlags : Flag
    {

    };

    struct Color
    {
        #ifdef MONOCHROME
        uint8_t color;
        #endif
    };

    class Base
    {
    public:
        constexpr Base() {};
        Flag flags = Flag(WidgetFlags::Hidden);
        WID_TYPE("None")
        WID_NAME
    };

    // Check if the flag is present
    template<typename T>
    constexpr bool has_flag(Flag src, T flag)
    {
        return src & Flag(flag);
    }

} // phi

#endif //PHIUI_COMMON_H

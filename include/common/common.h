//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_COMMON_H
#define PHIUI_COMMON_H

#include <cstdint>

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

#ifdef INCREASE_WIDGETS_LIMIT
    typedef ui16 Selector  // 65536 elements is maximum
#else
    typedef ui8 Selector;  // 255 elements is maximum
#endif

    struct Point
    {
        i16 x;
        i16 y;
    };

    struct Size
    {
        ui16 width;
        ui16 height;
    };

    enum class WidgetFlags : Flag
    {
        Disabled = 0b1,  // Cannot select widget, is rendered differently
        Unselectable = 0b10,  // This widget won't be selected
        Hidden = 0b100,  // This widget is not rendered, but constraints are present
        Spacer = 0b1000,  // This is a spacer expanding item
    };

    enum class ScreenFlags : Flag
    {
        Overlay = 0b1,  // This screen is a global overlay
        Opaque = 0b10,  // Screen background is translucent; TODO check how u8g2 handles this
    };

    enum class ScreenPolicy : Flag
    {
        Fixed,
        Vertical,
        Horizontal,
        Grid
    };

    class Base
    {
    public:
        Base() {};
        Flag flags = Flag(WidgetFlags::Hidden);
    };

} // phi

#endif //PHIUI_COMMON_H

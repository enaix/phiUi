//
// Created by Flynn on 26.03.2024.
//

#ifndef PHIUI_SKINS_COMMON_H
#define PHIUI_SKINS_COMMON_H

#include <cstdint>
#include <algorithm>

namespace phi
{

    // Constant string class
    template<std::size_t SIZE>
    class ConstStr
    {
    public:
        char str[SIZE];
        static constexpr std::size_t size() {return SIZE;};

        constexpr ConstStr(const char (&c)[SIZE])
        {
            std::copy_n(c, SIZE, str); // copy_n can be constexpr
        }
        // https://ctrpeach.io/posts/cpp20-string-literal-template-parameters/
    };

    // Wrapper for ConstStr type
    template<ConstStr STR>
    class StrID
    {
    public:
        constexpr StrID() {}
        //static constexpr char* str() {return STR.str;}
    };

    // ID macro that defines the widget type string
    #define WID_TYPE(x) static constexpr char type[] = x;
    #define WID_NAME(x) static constexpr char name[] = x;

    constexpr bool compare(char const* lhs, char const* rhs)
    {
        if (*lhs != *rhs) return false;

        if (*lhs == '\0' && *rhs == '\0') return true;

        if ((*lhs == '\0') != (*rhs == '\0')) return false;

        return compare(lhs + 1, rhs + 1);
    }

    // Concept that searches for the matching widget name and type
    /*template<typename Wid, ConstStr WidType> // SIZE will be deduced
    concept WidgetType = requires()
    {
        compare(Wid::type, WidType.str) || compare(Wid::name, WidType.str);
    };*/

}

#endif //PHIUI_SKINS_COMMON_H

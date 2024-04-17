//
// Created by Flynn on 19.03.2024.
//

#ifndef PHIUI_STATE_H
#define PHIUI_STATE_H

#include "phi_common.h"
#include "phi_containers.h"
#include "widgets.h"

// TODO think about dynamic imports
#include "default_skin.h"

namespace phi
{

    // Define a helper structure for SFINAE
    template<typename T, ConstStr STR>
    struct has_method {
        static constexpr WidName<STR> _name = WidName<STR>();

        template<typename U, typename W, ConstStr S>
        static auto test(W* wid, RENDERER_TYPE* renderer) -> decltype(std::declval<U>().template draw<_name, W>(wid, renderer), std::true_type());

        template<typename U, class Wid, ConstStr S>
        static std::false_type test(...);

        template<typename Wid>
        struct impl {
            static constexpr bool value = decltype(test<T, Wid, STR>(nullptr, nullptr))::value;
        };
    };

    template<ConstStr STR, class Wid>
    void skin_name_callback(Skin* skin, Wid* wid, RENDERER_TYPE* renderer)
    {
        constexpr WidName<STR> name;
        skin->draw<name, Wid>(wid, renderer);
    }

    class State
    {
    public:
        State() : enable_draw(false), _cur_screen(nullptr), _root(nullptr) {};

        void draw(RENDERER_TYPE* render);
        void constraint();

        void set_root(Screen* root) {_root = root;}
        void show() {enable_draw = true;}

        template<ConstStr STR, class Wid>
        void set_wid_name(Wid* wid)
        {
            constexpr WidName<STR> name;
            if constexpr (has_method<Skin, STR>::template impl<Wid>::value)
            {
                // Set draw function to widget
                wid->draw = &skin_name_callback<STR, Wid>;
            }
        }

    protected:
        // Screens
        Screen* _cur_screen; //
        Screen* _root; // Root screen that contains the underlying ones. Perhaps we only need _overlays
        Array<Screen*> _overlays; // Sticky screens that are always present
        Skin _skin;

        // Properties
        bool enable_draw;

        template<class Wid>
        void draw_wid(Wid* wid, RENDERER_TYPE* render);
    };

} // phi

#endif //PHIUI_STATE_H

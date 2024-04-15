//
// Created by Flynn on 19.03.2024.
//

#include "state.h"

#include <type_traits>

namespace phi
{

    void State::draw(RENDERER_TYPE* render)
    {
        draw_wid(_root, render);
        for (st i = 0; i < _root->widgets.size(); i++)
        {
            draw_wid(&_root->widgets[i], render);
        }
    }

    void State::constraint()
    {
        _root->size.width = DISPLAY_WIDTH; // TODO make it plugin-independent
        _root->size.height = DISPLAY_HEIGHT;

        if (!_root->is_init && _root->init)
            _root->init(_root, this); // Call init to create widgets

        _root->is_init = true;
        _root->constraint();
    }

    template<class Wid>
    void State::draw_wid(Wid* wid, RENDERER_TYPE* render)
    {
        constexpr WidType<Wid::type> type;
        //constexpr WidName<Wid::name> name;

        if (wid->draw)
            wid->draw(&_skin, wid, render);
        else
            _skin.draw<type, Wid>(wid, render);

    }

} // phi
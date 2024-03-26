//
// Created by Flynn on 19.03.2024.
//

#include "state.h"

namespace phi
{
    void State::draw(RENDERER_TYPE* render)
    {
        draw_wid(_root, render);
        for (st i = 0; i < _root->widgets.size(); i++)
        {
            draw_wid(_root->widgets[i], render);
        }
    }

    void State::constraint()
    {
        if (!_root->is_init && _root->init)
            _root->init();
        _root->is_init = true;
        _root->constraint();
    }

    template<class Wid>
    void State::draw_wid(Wid* wid, RENDERER_TYPE* render)
    {
        for (ui8 i = 0; i < wid->classes.size(); i++)
        {
            wid->classes[i](wid, render);
        }
    }

} // phi
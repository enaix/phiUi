//
// Created by Flynn on 23.01.2024.
//

#include "phi.h"

namespace phi
{
    Phi::Phi() : renderer({DISPLAY_WIDTH, DISPLAY_HEIGHT})
    {}

    void Phi::loop()
    {
        // Main Phi loop. Calls renderer
        renderer.clear();
        // Call the skin to redraw

#ifdef RENDERER_PAGE_BUFFER
        do
        {
            _state.draw(&renderer);
        } while (renderer.render());
#else
        _state.draw(&renderer);
        renderer.render();
#endif

        renderer.poll();
    }

    void Phi::set_root(Screen* root)
    {
        _state.set_root(root);
    }

    void Phi::show()
    {
        _state.constraint();
        _state.show();
    }
} // phi
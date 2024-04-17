//
// Created by Flynn on 16.04.2024.
//

#include "custom_options.h"
#include "phi.h"
#include "phi_common.h"
#include "widgets.h"

phi::Screen setup_phi(phi::Phi& phi)
{
    //auto phi = phi::Phi();

    auto screen = phi::Screen(nullptr);
    screen.screen_policy = phi::Flag(phi::ScreenPolicy::Vertical);
    screen.init = [](phi::Screen* parent, phi::State* state){
        for (phi::st i = 0; i < 6; i++)
        {
            phi::Widget wid = phi::Widget("");

            if (i == 5)
                state->set_wid_name<"BiosBox">(&wid);

            wid.parent = parent;
            wid.size_hint = {2, 2};
            wid.margin = phi::Margin{2, 2, 2, 2};
            wid.pos.x = i * 10;
            parent->widgets.append(wid);
        }
    };

    phi.set_root(&screen);

    phi.show();
    return screen;
}

void run(phi::Phi& phi)
{
    while(true) phi.loop();
}
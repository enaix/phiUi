//
// Created by Flynn on 21.02.2024.
//

#include "phi.h"

#include "common/common.h"
#include "widgets/widgets.h"

int main()
{
    auto phi = phi::Phi();

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

    while(true) phi.loop();

    return 0;
}
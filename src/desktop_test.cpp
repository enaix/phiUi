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
    screen.init = [](phi::Screen* parent){
        for (phi::st i = 0; i < 6; i++)
        {
            phi::Widget wid = phi::Widget(parent, {2, 2});
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
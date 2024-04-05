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
    screen.init = [](phi::Screen* parent){
        phi::Widget wid1 = phi::Widget(parent, {12, 6});
        phi::Widget wid2 = phi::Widget(parent, {12, 6});
        wid1.margin = phi::Margin{2, 2, 2, 2};
        wid2.margin = phi::Margin{2, 2, 2, 2};

        parent->widgets.append(wid1);
        parent->widgets.append(wid2);
    };

    phi.set_root(&screen);

    phi.show();

    while(true) phi.loop();

    return 0;
}
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

    phi.set_root(&screen);

    phi.show();

    while(true) phi.loop();

    return 0;
}
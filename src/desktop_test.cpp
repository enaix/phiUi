//
// Created by Flynn on 21.02.2024.
//

#include "phi.h"

#include "common/common.h"
#include "renderer/renderer.h"

int main()
{
    auto phi = phi::Phi();

    while(true)
    {
        phi.renderer.clear();
        phi.renderer.drawPixel({10, 10});
        phi.renderer.render();
    }

    return 0;
}
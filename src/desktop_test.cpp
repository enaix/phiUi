//
// Created by Flynn on 21.02.2024.
//

#include "phi.h"

#include "common/common.h"
#include "renderer/renderer.h"

int main()
{
    auto phi = phi::Phi();

    phi.renderer.drawPixel({10, 10});
    phi.renderer.render();

    return 0;
}
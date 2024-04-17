//
// Created by Flynn on 21.02.2024.
//

#include "custom_options.h"
#include "phi.h"
#include "phi_common.h"

#include "widgets.h"

#include "layout/test_layout.h"

#ifdef DESKTOP

int main()
{
    auto app = phi::Phi();

    auto screen = setup_phi(app);
    run(app);

    return 0;
}
#endif

#ifdef MONO_U8G2

phi::Phi app;
phi::Screen screen(nullptr);

void setup()
{
    screen = setup_phi(app);
}

void loop()
{
    app.loop();
}

#endif
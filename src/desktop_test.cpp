//
// Created by Flynn on 21.02.2024.
//

#ifdef MONO_U8G2

// Define u8g2 plugin params
#define MONO_U8G2_DISPLAY U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64
#define U8G2_PINS U8G2_R0, DISPLAY_CS, DISPLAY_DC, DISPLAY_RESET

#endif

#include "phi.h"

#include "common/common.h"
#include "widgets/widgets.h"

#include "test_layout.cpp"

#ifdef DESKTOP

int main()
{
    auto app = phi::Phi();

    setup_phi(app);
    run(app);

    return 0;
}
#endif

#ifdef MONO_U8G2

phi::Phi app;

void setup()
{
    setup_phi(app);
}

void loop()
{
    app.loop();
}

#endif
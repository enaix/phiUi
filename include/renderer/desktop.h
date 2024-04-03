//
// Created by Flynn on 21.02.2024.
//

#ifndef PHIUI_DESKTOP_H
#define PHIUI_DESKTOP_H

#include <SDL.h>

#include "common/options.h"
#include "renderer/renderer_base.h"

namespace phi
{

    class Desktop : public Renderer
    {
    public:
        Desktop(Point res);
        ~Desktop();

        void drawPixel(Point pos);
        void drawFilledRect(Point pos, Size size);
        void drawRect(Point pos, Size size);
        void setColor(Color color);
        void render();
        void clear();
    protected:
        SDL_Renderer* renderer = nullptr;
        SDL_Window* window = nullptr;
    };

} // phi

#endif //PHIUI_DESKTOP_H

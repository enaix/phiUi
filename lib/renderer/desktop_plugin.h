//
// Created by Flynn on 21.02.2024.
//

#include "phi_options.h"

#ifdef DESKTOP

#ifndef PHIUI_DESKTOP_H
#define PHIUI_DESKTOP_H

#include <SDL.h>

#include "renderer_base.h"

namespace phi
{

    class Desktop : public Renderer
    {
    public:
        explicit Desktop(Point res);
        ~Desktop();

        void drawPixel(Point pos);
        void drawFilledRect(Point pos, Size size);
        void drawRect(Point pos, Size size);
        void setColor(Color color);
        void render();
        void poll();
        void clear();
    protected:
        SDL_Renderer* renderer = nullptr;
        SDL_Window* window = nullptr;
        SDL_Event cur_event;
    };

} // phi

#endif //PHIUI_DESKTOP_H

#endif //DESKTOP

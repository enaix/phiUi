//
// Created by Flynn on 21.02.2024.
//

#ifndef PHIUI_DESKTOP_H
#define PHIUI_DESKTOP_H

#include <SDL.h>

#include "renderer/renderer.h"

#ifndef RENDERER_TYPE
class Desktop;
// Define the renderer type
#define RENDERER_TYPE Desktop
#endif

namespace phi
{

    class Desktop : public Renderer
    {
    public:
        Desktop(Point res);
        ~Desktop();

        void drawPixel(Point pos);
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

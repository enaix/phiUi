//
// Created by Flynn on 21.02.2024.
//

#include "phi_options.h"

#ifdef DESKTOP

#include "desktop_plugin.h"

namespace phi
{

    Desktop::Desktop(Point res) : Renderer(res)
    {
        SDL_Init(SDL_INIT_VIDEO);
        //SDL_CreateWindowAndRenderer(_res.x, _res.y, 0, &window, &renderer);

        window = SDL_CreateWindow("phi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _res.x * 5, _res.y * 5, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        SDL_RenderSetLogicalSize(renderer, _res.x, _res.y);

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    Desktop::~Desktop()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Desktop::drawPixel(phi::Point pos)
    {
        SDL_RenderDrawPoint(renderer, pos.x, pos.y);
    }

    void Desktop::drawFilledRect(Point pos, Size size)
    {
        SDL_Rect r;
        r.x = pos.x;
        r.y = pos.y;
        r.w = size.width;
        r.h = size.height;
        SDL_RenderFillRect(renderer, &r);
    }

    void Desktop::drawRect(Point pos, Size size)
    {
        SDL_Rect r;
        r.x = pos.x;
        r.y = pos.y;
        r.w = size.width;
        r.h = size.height;
        SDL_RenderDrawRect(renderer, &r);
    }

    void Desktop::setColor(phi::Color color)
    {
        #ifdef MONOCHROME
        if (color.color)
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        else
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        #endif
    }

    void Desktop::render()
    {
        SDL_RenderPresent(renderer);
    }

    void Desktop::clear()
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }

    void Desktop::poll()
    {
        if (SDL_PollEvent(&cur_event))
        {
            if (cur_event.type == SDL_QUIT)
            {
                // Shutdown
                exit(0);
            }
        }
    }

} // phi

#endif
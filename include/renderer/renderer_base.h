//
// Created by Flynn on 21.02.2024.
//

#ifndef PHIUI_RENDERER_BASE_H
#define PHIUI_RENDERER_BASE_H

#include "common/common.h"

namespace phi
{

    class Renderer
    {
    public:
        Renderer(Point res) : _res(res) {};
        ~Renderer() {};

        void drawPixel(Point pos) {};
        void setColor(Color color) {};
        void render() {};
        void clear() {};
    protected:
        Point _res;
    };

} // phi

#endif //PHIUI_RENDERER_BASE_H

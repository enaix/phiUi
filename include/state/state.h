//
// Created by Flynn on 19.03.2024.
//

#ifndef PHIUI_STATE_H
#define PHIUI_STATE_H

#include "common/common.h"
#include "common/containers.h"
#include "widgets/widgets.h"

// TODO think about dynamic imports
#include "skins/default.h"

namespace phi
{

    class State
    {
    public:
        State() : enable_draw(false), _cur_screen(nullptr), _root(nullptr) {};

        void draw(RENDERER_TYPE* render);
        void constraint();

        void set_root(Screen* root) {_root = root;}
        void show() {enable_draw = true;}

    protected:
        // Screens
        Screen* _cur_screen; //
        Screen* _root; // Root screen that contains the underlying ones. Perhaps we only need _overlays
        Array<Screen*> _overlays; // Sticky screens that are always present

        // Properties
        bool enable_draw;

        template<class Wid>
        void draw_wid(Wid* wid, RENDERER_TYPE* render);
    };

} // phi

#endif //PHIUI_STATE_H

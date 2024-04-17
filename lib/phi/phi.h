//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_PHI_H
#define PHIUI_PHI_H

#include "phi_renderer.h"

#include "phi_common.h"
#include "widgets.h"
#include "state.h"

namespace phi
{

    class Phi
    {
    public:
        Phi();

        RENDERER_TYPE renderer;

        void loop();

        void set_root(Screen* root);

        void show();

        template<class Wid, ConstStr STR>
        void set_wid_name(Wid* wid) {_state.set_wid_name<STR>(wid);};

    protected:
        State _state;
    };

} // phi

#endif //PHIUI_PHI_H

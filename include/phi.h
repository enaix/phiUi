//
// Created by Flynn on 23.01.2024.
//

#ifndef PHIUI_PHI_H
#define PHIUI_PHI_H

#include "renderer/renderer.h"

#include "common/common.h"
#include "widgets/widgets.h"
#include "state/state.h"

namespace phi
{

    class Phi
    {
    public:
#ifdef MONO_U8G2
        Phi(MONO_U8G2_DISPLAY display);
#endif
#ifdef DESKTOP
        Phi();
#endif

#ifdef MONO_U8G2
        MONO_U8G2_DISPLAY u8g2;
        // TODO move display declaration to renderer
#endif

#ifdef DESKTOP
        RENDERER_TYPE renderer;
#endif
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

//
// Created by Y.A. on 2017/08/01.
//

#ifndef HUMANITY_BATTLESCENE_BEGINNINGPART_H
#define HUMANITY_BATTLESCENE_BEGINNINGPART_H

#include "../Part.h"

namespace BattleScene {
    class BeginningPart : public Part {
    public:
        PartExitStatus play();

    private:
        void update();
        void show();
    };
}

#endif //HUMANITY_BATTLESCENE_BEGINNINGPART_H

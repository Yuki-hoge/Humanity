//
// Created by Y.A. on 2017/08/01.
//

#ifndef HUMANITY_BATTLESCENE_BEGINNINGPART_H
#define HUMANITY_BATTLESCENE_BEGINNINGPART_H

#include "../Part.h"

namespace BattleScene {
    class BeginningPart : public Part {
    public:
        PartExitStatus play() override;
    };
}

#endif //HUMANITY_BATTLESCENE_BEGINNINGPART_H

//
// Created by Y.A. on 2017/08/01.
//

#ifndef HUMANITY_BATTLESCENE_ENEMYEMERGINGPART_H
#define HUMANITY_BATTLESCENE_ENEMYEMERGINGPART_H


#include "../Part.h"

namespace BattleScene {
    class EnemyEmergingPart : public Part {
    public:
        void initialize();
        PartExitStatus play();

    private:
        void update();
        void show();

    };
}


#endif //HUMANITY_BATTLESCENE_ENEMYEMERGINGPART_H

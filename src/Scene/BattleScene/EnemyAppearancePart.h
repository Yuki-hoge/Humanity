//
// Created by Y.A. on 2017/08/01.
//

#ifndef HUMANITY_BATTLESCENE_ENEMYAPPEARANCEPART_H
#define HUMANITY_BATTLESCENE_ENEMYAPPEARANCEPART_H


#include "../Part.h"

namespace BattleScene {
    class EnemyAppearancePart : public Part {
    public:
        void initialize() override;
        PartExitStatus play() override;

    private:
        void update() override;
        void show() override;
        bool is_done_;

    };
}


#endif //HUMANITY_BATTLESCENE_ENEMYAPPEARANCEPART_H

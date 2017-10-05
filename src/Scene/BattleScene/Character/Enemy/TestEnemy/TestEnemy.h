//
// Created by Y.A. on 2017/08/10.
//

#ifndef HUMANITY_BATTLESCENE_CHARACTER_ENEMY_TESTENEMY_TESTENEMY_H
#define HUMANITY_BATTLESCENE_CHARACTER_ENEMY_TESTENEMY_TESTENEMY_H

//#include "../../Character.h"
//#include "../EnemyStatus.h"

#include "../Enemy.h"

namespace BattleScene::Character::Enemy {
    class EnemyStatus;
}

namespace BattleScene::Character::Enemy::TestEnemy {
    class TestEnemy : public Enemy {
    public:
        void initialize() override;

        void update() override;

        void draw() override;

        void finalize() override;

//        void hit(int damage);

    };

}


#endif //HUMANITY_BATTLESCENE_CHARACTER_ENEMY_TESTENEMY_TESTENEMY_H

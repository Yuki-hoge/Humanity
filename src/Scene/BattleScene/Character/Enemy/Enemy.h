//
// Created by Y.A. on 2017/08/10.
//

#ifndef HUMANITY_ENEMY_H
#define HUMANITY_ENEMY_H

//#include "EnemyStatus.h"
namespace BattleScene::Character::Enemy {
    class EnemyStatus;
}

namespace BattleScene::Character::Enemy {
    class Enemy {
    public:
        virtual void initialize() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void finalize() = 0;
        bool isAppeared(){
                return is_appeared_;
        };

    protected:
        EnemyStatus *current_status_;
        EnemyStatus *appearing_;
        EnemyStatus *neutral_;
        int health;
        bool is_appeared_;
    };
}

#endif //HUMANITY_ENEMY_H

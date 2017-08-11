//
// Created by Y.A. on 2017/08/10.
//

#ifndef HUMANITY_BATTLESCENE_CHARACTER_ENEMY_ENEMYSTATUS_H
#define HUMANITY_BATTLESCENE_CHARACTER_ENEMY_ENEMYSTATUS_H

//#include "../Status.h"

namespace BattleScene::Character::Enemy {
    class EnemyStatus {
    public:
        virtual void initialize() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void finalize() = 0;
        virtual bool isDone() = 0;

    protected:
        bool is_done_;
    };
}


#endif //HUMANITY_BATTLESCENE_CHARACTER_ENEMY_ENEMYSTATUS_H

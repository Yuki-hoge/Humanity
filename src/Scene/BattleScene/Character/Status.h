//
// Created by Y.A. on 2017/08/06.
//

#ifndef HUMANITY_BATTLESCENE_CHARACTER_STATUS_STATUS_H
#define HUMANITY_BATTLESCENE_CHARACTER_STATUS_STATUS_H

namespace BattleScene::Character::Status {
    class Status {
    public:
        virtual bool canMove();
        virtual bool canAttack();
        virtual bool canHit();
        virtual void update() = 0;
        virtual void draw() = 0;
    };
}


#endif //HUMANITY_STATUS_H

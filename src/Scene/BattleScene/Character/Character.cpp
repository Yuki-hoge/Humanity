//
// Created by Y.A. on 2017/08/01.
//

#include "Character.h"
#include "Status.h"

//    void Character::Character::hit(int damage) {
//
//    }
void BattleScene::Character::Character::hit(int damage) {
    if (current_status_->canHit()) {
        health -= damage;
    }
}

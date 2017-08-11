//
// Created by Y.A. on 2017/08/01.
//

#ifndef HUMANITY_BATTLESCENE_COMPONENTS_H
#define HUMANITY_BATTLESCENE_COMPONENTS_H

#include <vector>
#include "Character/Enemy/Enemy.h"

//class Enemy;
class Humanity;
class Attack;

namespace BattleScene {
    extern Humanity *g_humanity;
    extern std::vector<Character::Enemy::Enemy *> g_enemies;
    extern std::vector<Attack *> g_attacks;
}

#endif //HUMANITY_BATTLESCENE_COMPONENTS_H

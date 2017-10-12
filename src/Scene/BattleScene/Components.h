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
class SDL_Texture;
class Mix_Chunk;

namespace BattleScene {
    extern Humanity *g_humanity;
    extern std::vector<std::vector<Character::Enemy::Enemy *>> g_enemy_map;
    extern std::vector<Attack *> g_attacks;
    extern SDL_Texture *g_background_texture;
    extern Mix_Chunk *g_enemy_appearing_se;
}

#endif //HUMANITY_BATTLESCENE_COMPONENTS_H

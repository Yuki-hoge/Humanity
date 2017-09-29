//
// Created by Y.A. on 2017/08/01.
//

#include "Components.h"

namespace BattleScene {
    Humanity *g_humanity = nullptr;
    std::vector<Character::Enemy::Enemy *> g_enemies;
    std::vector<Attack *> g_attacks;
    SDL_Texture *g_background_texture = nullptr;
}
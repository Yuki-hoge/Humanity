//
// Created by Y.A. on 2017/08/01.
//

#include "Components.h"
#define MAP_SIZE 3

namespace BattleScene {
    using vvCEE = std::vector<std::vector<Character::Enemy::Enemy *>>;

    Humanity *g_humanity = nullptr;
    vvCEE g_enemy_map(MAP_SIZE, std::vector<Character::Enemy::Enemy *>(MAP_SIZE));
    std::vector<Attack *> g_attacks;
    SDL_Texture *g_background_texture = nullptr;
    Mix_Chunk *g_enemy_appearing_se = nullptr;
}
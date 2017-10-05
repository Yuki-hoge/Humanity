//
// Created by Y.A. on 2017/10/03.
//

#include "EnemyStatus.h"
#include "../../../../tools/SDL_helper.h"
#include "../../../../GameDefs.h"

namespace GD = GameDefs;

void BattleScene::Character::Enemy::EnemyStatus::do_common_init(std::string status_img_path) {
    is_done_ = false;
    status_img_ = SDL_helper::myCreateTextureFromIMG(GD::g_sdl_renderer, status_img_path);
    SDL_QueryTexture(status_img_, nullptr, nullptr, &img_width_, &img_height_);
}

void BattleScene::Character::Enemy::EnemyStatus::finalize() {
    SDL_DestroyTexture(status_img_);
    status_img_ = nullptr;
}

bool BattleScene::Character::Enemy::EnemyStatus::isDone() {
    return is_done_;
}

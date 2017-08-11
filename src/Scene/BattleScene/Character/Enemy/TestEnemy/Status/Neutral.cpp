//
// Created by Y.A. on 2017/08/10.
//

#include "Neutral.h"
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "../../../../../../tools/SDL_helper.h"
#include "../../../../../../GameDefs.h"

using namespace GameDefs;

void BattleScene::Character::Enemy::TestEnemy::Status::Neutral::initialize() {
    neutral_img_ = SDL_helper::myCreateTextureFromIMG(g_sdl_renderer, "data/battle_scene/Character/Enemy/TestEnemy/static_img.png");
}

void BattleScene::Character::Enemy::TestEnemy::Status::Neutral::update() {
    // do nothing
}

void BattleScene::Character::Enemy::TestEnemy::Status::Neutral::draw() {
    static SDL_Rect draw_rect = (SDL_Rect){170,350,100,100};
    SDL_RenderCopy(g_sdl_renderer, neutral_img_, nullptr, &draw_rect);
}

void BattleScene::Character::Enemy::TestEnemy::Status::Neutral::finalize() {
    SDL_DestroyTexture(neutral_img_);
    neutral_img_ = nullptr;
}

bool BattleScene::Character::Enemy::TestEnemy::Status::Neutral::isDone() {
    return true;
}


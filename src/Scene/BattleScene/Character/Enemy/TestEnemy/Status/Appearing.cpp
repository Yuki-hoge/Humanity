//
// Created by Y.A. on 2017/08/11.
//

#include "Appearing.h"
#include <SDL2/SDL.h>
#include "../../../../../../tools/SDL_helper.h"
#include "../../../../../../GameDefs.h"

#define NUM_OF_IMGS 3

using namespace GameDefs;

void BattleScene::Character::Enemy::TestEnemy::Status::Appearing::initialize() {
    is_done_ = false;
    std::string img_path = "data/battle_scene/Character/Enemy/TestEnemy/appearing_img.png";
    appearing_img_ = SDL_helper::myCreateTextureFromIMG(g_sdl_renderer, img_path);
    SDL_QueryTexture(appearing_img_, nullptr, nullptr, &img_width_, &img_height_);
    img_width_ /= NUM_OF_IMGS;

    for (int i = 0; i < NUM_OF_IMGS; ++i) {
        img_rects_.push_back((SDL_Rect){img_width_*i,0,img_height_,img_width_});
    }

    std::string se_path = "data/sound/battle_scene/enemy_appearing_se.wav";
    appearing_se_ = SDL_helper::myLoadWAV(se_path);
}

void BattleScene::Character::Enemy::TestEnemy::Status::Appearing::update() {
    static int frame_ctr = 0;
    if (is_done_) return;
    if (frame_ctr >= TOTAL_ENEMY_APPEARANCE_FRAMES) {
        is_done_ = true;
        return;
    }

    if (frame_ctr == 5) Mix_PlayChannel(-1, appearing_se_, 0);

    img_rect_ = img_rects_[frame_ctr/(TOTAL_ENEMY_APPEARANCE_FRAMES/NUM_OF_IMGS)];
    frame_ctr++;
}

void BattleScene::Character::Enemy::TestEnemy::Status::Appearing::draw() {
    static SDL_Rect draw_rect = (SDL_Rect){170,350,100,100};
    SDL_RenderCopy(g_sdl_renderer, appearing_img_, &img_rect_, &draw_rect);

}

void BattleScene::Character::Enemy::TestEnemy::Status::Appearing::finalize() {
    SDL_DestroyTexture(appearing_img_);
    appearing_img_ = nullptr;
    Mix_FreeChunk(appearing_se_);

}

bool BattleScene::Character::Enemy::TestEnemy::Status::Appearing::isDone() {
    return is_done_;
}

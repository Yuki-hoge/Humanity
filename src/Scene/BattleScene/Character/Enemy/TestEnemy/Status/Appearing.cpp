//
// Created by Y.A. on 2017/08/11.
//

#include "Appearing.h"
#include <SDL2/SDL.h>
#include "../../../../../../tools/SDL_helper.h"
#include "../../../../../../GameDefs.h"
#include "../../../../BattleSceneDefs.h"

#define NUM_OF_IMGS 3

namespace GD = GameDefs;
namespace BSD = BattleScene::Defs;

void BattleScene::Character::Enemy::TestEnemy::Status::Appearing::initialize() {
    is_done_ = false;
    std::string img_path = "data/battle_scene/Character/Enemy/TestEnemy/appearing_img.png";
    appearing_img_ = SDL_helper::myCreateTextureFromIMG(GD::g_sdl_renderer, img_path);
    SDL_QueryTexture(appearing_img_, nullptr, nullptr, &img_width_, &img_height_);
    img_width_ /= NUM_OF_IMGS;

    for (int i = 0; i < NUM_OF_IMGS; ++i) {
        img_rects_.push_back((SDL_Rect){img_width_*i,0,img_width_,img_height_});
    }

    std::string se_path = "data/sound/battle_scene/enemy_appearing_se.wav";
    appearing_se_ = SDL_helper::myLoadWAV(se_path);
}

void BattleScene::Character::Enemy::TestEnemy::Status::Appearing::update() {
    static int frame_ctr = 0;
    if (is_done_) return;
    if (frame_ctr >= BSD::TOTAL_ENEMY_APPEARANCE_FRAMES) {
        is_done_ = true;
        return;
    }

    if (frame_ctr == 5) Mix_PlayChannel(-1, appearing_se_, 0);

    img_rect_ = img_rects_[frame_ctr/(BSD::TOTAL_ENEMY_APPEARANCE_FRAMES/NUM_OF_IMGS)];
    frame_ctr++;
}

void BattleScene::Character::Enemy::TestEnemy::Status::Appearing::draw() {
    static int draw_rect_width = BSD::CHARACTER_DRAW_RECT_WIDTH;
    static int draw_rect_height
            = static_cast<int>(1.0*draw_rect_width*img_height_/img_width_);
    static SDL_Rect draw_rect
            = (SDL_Rect){
                    GD::WINDOW_WIDTH*5/6 - (GD::WINDOW_WIDTH/6-draw_rect_width)/2 - draw_rect_width,
                    GD::WINDOW_HEIGHT-121-draw_rect_height,
                    draw_rect_width,
                    draw_rect_height};
    SDL_RenderCopy(GD::g_sdl_renderer, appearing_img_, &img_rect_, &draw_rect);

}

void BattleScene::Character::Enemy::TestEnemy::Status::Appearing::finalize() {
    SDL_DestroyTexture(appearing_img_);
    appearing_img_ = nullptr;
    if (!appearing_se_) {
        Mix_FreeChunk(appearing_se_);
        appearing_se_ = nullptr;
    }

}

bool BattleScene::Character::Enemy::TestEnemy::Status::Appearing::isDone() {
    return is_done_;
}

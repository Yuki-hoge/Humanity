//
// Created by Y.A. on 2017/08/11.
//

#include "TestEnemyAppearing.h"
#include <SDL2/SDL.h>
#include "../../../../../tools/SDL_helper.h"
#include "../../../../../GameDefs.h"
#include "../../../BattleSceneDefs.h"
#include "../../../Components.h"

#define NUM_OF_APPERING_IMGS 3

namespace GD = GameDefs;
namespace BSD = BattleScene::Defs;

void BattleScene::Character::Enemy::TestEnemy::TestEnemyAppearing::initialize() {
    std::string status_img_path = "data/battle_scene/Character/Enemy/TestEnemy/appearing_img.png";
    do_common_init(status_img_path);

    img_width_ /= NUM_OF_APPERING_IMGS;
    for (int i = 0; i < NUM_OF_APPERING_IMGS; ++i) {
        img_rects_.push_back((SDL_Rect){img_width_*i,0,img_width_,img_height_});
    }
}

void BattleScene::Character::Enemy::TestEnemy::TestEnemyAppearing::update() {
    static int frame_ctr = 0;
    if (is_done_) return;
    if (frame_ctr >= BSD::TOTAL_ENEMY_APPEARANCE_FRAMES) {
        is_done_ = true;
        return;
    }

    if (frame_ctr == 5) Mix_PlayChannel(-1, g_enemy_appearing_se, 0);

    current_img_rect_ = img_rects_[frame_ctr/(BSD::TOTAL_ENEMY_APPEARANCE_FRAMES/NUM_OF_APPERING_IMGS)];
    frame_ctr++;
}

void BattleScene::Character::Enemy::TestEnemy::TestEnemyAppearing::draw() {
    static int draw_rect_width = BSD::CHARACTER_DRAW_RECT_WIDTH;
    static int draw_rect_height
            = static_cast<int>(1.0*draw_rect_width*img_height_/img_width_);

    // 現時点でキャラの描写位置を計算している箇所
    // TODO: キャラの位置はゲーム上の論理座標から計算できなければならない
    static SDL_Rect draw_rect
            = (SDL_Rect){
                    GD::WINDOW_WIDTH*5/6 - (GD::WINDOW_WIDTH/6-draw_rect_width)/2 - draw_rect_width,
                    GD::WINDOW_HEIGHT-121-draw_rect_height,
                    draw_rect_width,
                    draw_rect_height};
    SDL_RenderCopy(GD::g_sdl_renderer, status_img_, &current_img_rect_, &draw_rect);

}

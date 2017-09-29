//
// Created by Y.A. on 2017/08/10.
//

#include "Neutral.h"
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "../../../../../../tools/SDL_helper.h"
#include "../../../../../../GameDefs.h"
#include "../../../../BattleSceneDefs.h"

namespace GD = GameDefs;
namespace BSD = BattleScene::Defs;

void BattleScene::Character::Enemy::TestEnemy::Status::Neutral::initialize() {
    neutral_img_ = SDL_helper::myCreateTextureFromIMG(GD::g_sdl_renderer, "data/battle_scene/Character/Enemy/TestEnemy/static_img.png");
    SDL_QueryTexture(neutral_img_, nullptr, nullptr, &img_width_, &img_height_);
}

void BattleScene::Character::Enemy::TestEnemy::Status::Neutral::update() {
    // do nothing
}

void BattleScene::Character::Enemy::TestEnemy::Status::Neutral::draw() {
    static int draw_rect_width = BSD::CHARACTER_DRAW_RECT_WIDTH;
    static int draw_rect_height
            = static_cast<int>(1.0*draw_rect_width*img_height_/img_width_);
    static SDL_Rect draw_rect
            = (SDL_Rect){
                    GD::WINDOW_WIDTH*5/6 - (GD::WINDOW_WIDTH/6-draw_rect_width)/2 - draw_rect_width,
                    GD::WINDOW_HEIGHT-121-draw_rect_height,
                    draw_rect_width,
                    draw_rect_height};
    SDL_RenderCopy(GD::g_sdl_renderer, neutral_img_, nullptr, &draw_rect);
}

void BattleScene::Character::Enemy::TestEnemy::Status::Neutral::finalize() {
    SDL_DestroyTexture(neutral_img_);
    neutral_img_ = nullptr;
}

bool BattleScene::Character::Enemy::TestEnemy::Status::Neutral::isDone() {
    return true;
}


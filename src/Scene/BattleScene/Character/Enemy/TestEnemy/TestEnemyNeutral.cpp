//
// Created by Y.A. on 2017/08/10.
//

#include "TestEnemyNeutral.h"
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "../../../../../tools/SDL_helper.h"
#include "../../../../../GameDefs.h"
#include "../../../BattleSceneDefs.h"

namespace GD = GameDefs;
namespace BSD = BattleScene::Defs;

void BattleScene::Character::Enemy::TestEnemy::TestEnemyNeutral::initialize() {
    std::string status_img_path = "data/battle_scene/Character/Enemy/TestEnemy/static_img.png";
    do_common_init(status_img_path);
    is_done_ = true;
}

void BattleScene::Character::Enemy::TestEnemy::TestEnemyNeutral::update() {
    // do nothing
}

void BattleScene::Character::Enemy::TestEnemy::TestEnemyNeutral::draw() {
    static int draw_rect_width = BSD::CHARACTER_DRAW_RECT_WIDTH;
    static int draw_rect_height
            = static_cast<int>(1.0*draw_rect_width*img_height_/img_width_);
    static SDL_Rect *draw_rect
            = new SDL_Rect{
                    GD::WINDOW_WIDTH*5/6 - (GD::WINDOW_WIDTH/6-draw_rect_width)/2 - draw_rect_width,
                    GD::WINDOW_HEIGHT-121-draw_rect_height,
                    draw_rect_width,
                    draw_rect_height};
    draw_rect->x -= 50;
    draw_rect->y -= 50;
    SDL_RenderCopy(GD::g_sdl_renderer, status_img_, nullptr, draw_rect);
}

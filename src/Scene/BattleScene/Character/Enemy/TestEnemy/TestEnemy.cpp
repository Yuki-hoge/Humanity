//
// Created by Y.A. on 2017/08/10.
//

#include "TestEnemy.h"
#include "Status/Neutral.h"
#include "Status/Appearing.h"
#include "../../../../../tools/SDL_helper.h"
#include "../../../../../GameDefs.h"
#include "../../../BattleSceneDefs.h"

#define TEST_ENEMY_HEALTH 40

namespace GD = GameDefs;
namespace BSD = BattleScene::Defs;

void BattleScene::Character::Enemy::TestEnemy::TestEnemy::initialize() {
    current_status_ = nullptr;
    neutral_ = new Status::Neutral();
    neutral_->initialize();
    appearing_ = new Status::Appearing();
    appearing_->initialize();

    is_appeared_ = false;
    health = TEST_ENEMY_HEALTH;

}

void BattleScene::Character::Enemy::TestEnemy::TestEnemy::update() {
    if (!is_appeared_ && !appearing_->isDone()) {
        current_status_ = appearing_;
    } else {
        is_appeared_ = true;
        current_status_ = neutral_;
    }
    current_status_->update();

}

void BattleScene::Character::Enemy::TestEnemy::TestEnemy::draw() {
    current_status_->draw();
    auto health_texture
            = SDL_helper::myCreateBlackStrTexture(GD::g_font, std::to_string(health*10));
    static int tw, th, draw_rect_width, draw_rect_height = BSD::HEALTH_DRAW_RECT_HEIGHT;
    SDL_QueryTexture(health_texture, nullptr, nullptr, &tw, &th);
    draw_rect_width
            = static_cast<int>(1.0*draw_rect_height*tw/th);
    SDL_Rect health_draw_rect
            = (SDL_Rect){
                    GD::WINDOW_WIDTH*5/6 - (GD::WINDOW_WIDTH/6-draw_rect_width)/2 - draw_rect_width,
                    GD::WINDOW_HEIGHT-121,
                    draw_rect_width,
                    draw_rect_height
            };
    SDL_RenderCopy(GameDefs::g_sdl_renderer, health_texture, nullptr, &health_draw_rect);

}

void BattleScene::Character::Enemy::TestEnemy::TestEnemy::finalize() {
    current_status_ = nullptr;
    appearing_->finalize(); appearing_ = nullptr;
    neutral_ ->finalize(); neutral_ = nullptr;
}

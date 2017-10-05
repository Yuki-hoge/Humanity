//
// Created by Y.A. on 2017/08/10.
//

#include "TestEnemy.h"
#include "TestEnemyNeutral.h"
#include "TestEnemyAppearing.h"
#include "../../../../../tools/SDL_helper.h"
#include "../../../../../GameDefs.h"
#include "../../../BattleSceneDefs.h"

#define TEST_ENEMY_HEALTH 40

void BattleScene::Character::Enemy::TestEnemy::TestEnemy::initialize() {
    current_status_ = nullptr;
    neutral_ = new TestEnemyNeutral();
    neutral_->initialize();
    appearing_ = new TestEnemyAppearing();
    appearing_->initialize();

    is_appeared_ = false;
    health_ = TEST_ENEMY_HEALTH;
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
    drawHealth();
}

void BattleScene::Character::Enemy::TestEnemy::TestEnemy::finalize() {
    current_status_ = nullptr;
    appearing_->finalize(); appearing_ = nullptr;
    neutral_ ->finalize(); neutral_ = nullptr;
}

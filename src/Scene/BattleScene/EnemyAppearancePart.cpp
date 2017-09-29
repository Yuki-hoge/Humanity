//
// Created by Y.A. on 2017/08/01.
//

#include "EnemyAppearancePart.h"
#include <SDL2/SDL.h>
#include "../PartExitStatus.h"
#include "Character/Enemy/TestEnemy/TestEnemy.h"
#include "../../tools/SDL_helper.h"
#include "../../GameDefs.h"
#include "Components.h"
#include "../../tools/Timer.h"
#include "BattleScene.h"

namespace BattleScene {
    void EnemyAppearancePart::initialize() {
        auto *te = new Character::Enemy::TestEnemy::TestEnemy();
        te->initialize();
        g_enemies.push_back(te);
        is_done_ = false;
    }

    PartExitStatus EnemyAppearancePart::play() {
        SDL_Delay(400);
        Timer timer;
        while (true) {
            timer.restart();

            update();
            if (is_done_) {
                SDL_Delay(10500);
                return PartExitStatus::QUIT;
            }
            sleepAtMost2F(timer);
            show();
        }
    }

    void EnemyAppearancePart::update() {
        if (is_done_) return;

        bool are_all_appeared = true;
        for (const auto& enemy : g_enemies) {
            if (!enemy->isAppeared()) {
                enemy->update();
                are_all_appeared = false;
                break;
            }
        }

        is_done_ = are_all_appeared;
    }

    void EnemyAppearancePart::show() {
        SDL_helper::drawWhiteBack(GameDefs::g_sdl_renderer);
        BattleScene::drawBackGround();
        for (const auto& enemy : g_enemies) {
            enemy->draw();
        }
        SDL_RenderPresent(GameDefs::g_sdl_renderer);
    }

}
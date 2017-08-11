//
// Created by Y.A. on 2017/08/01.
//

#include "EnemyEmergingPart.h"
#include <SDL2/SDL.h>
#include "../PartExitStatus.h"
#include "Character/Enemy/TestEnemy/TestEnemy.h"
#include "../../tools/SDL_helper.h"
#include "../../GameDefs.h"
#include "Components.h"

namespace BattleScene {
    void EnemyEmergingPart::initialize() {
        auto *te = new Character::Enemy::TestEnemy::TestEnemy();
        te->initialize();
        g_enemies.push_back(te);
    }

    PartExitStatus EnemyEmergingPart::play() {
        SDL_helper::drawWhiteBack(GameDefs::g_sdl_renderer);
        for (const auto& enemy : g_enemies) {
            enemy->draw();
        }
        SDL_RenderPresent(GameDefs::g_sdl_renderer);
        SDL_Delay(500);
        return PartExitStatus::CONTINUE;
    }

    void EnemyEmergingPart::update() {

    }

    void EnemyEmergingPart::show() {

    }

}
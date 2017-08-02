//
// Created by Y.A. on 2017/07/13.
//

#include "BattleScene.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../../GameDefs.h"
#include "../../tools/SDL_helper.h"
#include "BeginningPart.h"
#include "EnemyEmergingPart.h"

namespace BattleScene {
    void BattleScene::initialize() {
        scene_type_ = SceneType::BATTLE;
//    battle_bgm_ = SDL_helper::myLoadMUS("data/battle_scene/sound/battle_bgm.wav");
    }

    SceneExitStatus BattleScene::play() {
        playBeginningPart();
//    Mix_PlayMusic(battle_bgm_, -1);
        playEnemyEmergingPart();

        return SceneExitStatus::QUIT;
    }

    void BattleScene::finalize() {

    }

    void BattleScene::update() {

    }

    void BattleScene::show() {

    }

    void BattleScene::playBeginningPart() {
        BeginningPart beginningPart;
        beginningPart.play();
    }

    void BattleScene::playEnemyEmergingPart() {
        EnemyEmergingPart enemyEmergingPart;
        enemyEmergingPart.initialize();
        enemyEmergingPart.play();
    }
}

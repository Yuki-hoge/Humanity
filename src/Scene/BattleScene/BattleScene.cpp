//
// Created by Y.A. on 2017/07/13.
//

#include "BattleScene.h"
#include <iostream>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "../../GameDefs.h"
#include "../../tools/SDL_helper.h"
#include "BeginningPart.h"
#include "EnemyAppearancePart.h"
#include "Components.h"
#include "BattleSceneDefs.h"

namespace GD = GameDefs;
namespace BSD = BattleScene::Defs;
using vvCCE = std::vector<std::vector<BattleScene::Character::Enemy::Enemy *>>;

namespace BattleScene {
    void BattleScene::initialize() {
        scene_type_ = SceneType::BATTLE;
        battle_bgm_ = SDL_helper::myLoadMUS("data/sound/battle_scene/battle_bgm.wav");

        g_background_texture = SDL_helper::myCreateTextureFromIMG(
                GD::g_sdl_renderer,
                "data/battle_scene/background.png");
        g_enemy_appearing_se = SDL_helper::myLoadWAV(
                "data/sound/battle_scene/enemy_appearing_se.wav");

        // Initialize Enemy Map
//        vvCCE tmp(3, std::vector<Character::Enemy::Enemy *>(3));
//        g_enemy_map.clear(); g_enemy_map = std::move(tmp);
        for (auto& row : g_enemy_map) {
            for (auto elem : row) {
                elem = nullptr;
            }
        }
    }

    SceneExitStatus BattleScene::play() {
        playBeginningPart();
        Mix_PlayMusic(battle_bgm_, -1);
        playEnemyEmergingPart();

        return SceneExitStatus::QUIT;
    }

    void BattleScene::finalize() {
        if (!g_enemy_map.empty()) {
            for (auto& row : g_enemy_map) {
                for (auto enemy : row) {
                    if (enemy) {
                        enemy->finalize();
                        delete enemy;
                        enemy = nullptr;
                    }
                }
            }
        }

        if (g_background_texture) {
            SDL_DestroyTexture(g_background_texture);
            g_background_texture = nullptr;
        }

        if (g_enemy_appearing_se) {
            Mix_FreeChunk(g_enemy_appearing_se);
            g_enemy_appearing_se = nullptr;
        }
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
        EnemyAppearancePart enemyAppearancePart;
        enemyAppearancePart.initialize();
        enemyAppearancePart.play();
    }

    void BattleScene::drawBackGround() {
        static bool is_called_at_first = true;
        static int tw, th;
        static SDL_Rect draw_rect;
        if (is_called_at_first && g_background_texture) {
            SDL_QueryTexture(g_background_texture, nullptr, nullptr, &tw, &th);

            int draw_rect_width = GD::WINDOW_WIDTH;
            int draw_rect_height = static_cast<int>(1.0*draw_rect_width*th/tw);
            draw_rect = (SDL_Rect) {
                    GD::WINDOW_WIDTH - draw_rect_width,
                    GD::WINDOW_HEIGHT - draw_rect_height - BSD::BOTTOM_MERGIN,
                    draw_rect_width,
                    draw_rect_height
            };
            is_called_at_first = false;
        }

        SDL_RenderCopy(GameDefs::g_sdl_renderer, g_background_texture, nullptr, &draw_rect);
    }
}

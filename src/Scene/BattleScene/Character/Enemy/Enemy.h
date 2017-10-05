//
// Created by Y.A. on 2017/08/10.
//

#ifndef HUMANITY_BATTLESCENE_CHARACTER_ENEMY_ENEMY_H
#define HUMANITY_BATTLESCENE_CHARACTER_ENEMY_ENEMY_H

//#include "EnemyStatus.h"
#include "../../../../GameDefs.h"
#include "../../BattleSceneDefs.h"
#include "../../../../tools/SDL_helper.h"

namespace GD = GameDefs;
namespace BSD = BattleScene::Defs;

class SDL_Rect;
namespace BattleScene::Character::Enemy {
    class EnemyStatus;
}

namespace BattleScene::Character::Enemy {
    class Enemy {
    public:
        virtual void initialize() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void finalize() = 0;
        bool isAppeared(){
                return is_appeared_;
        };

    protected:
        EnemyStatus *current_status_;
        EnemyStatus *appearing_;
        EnemyStatus *neutral_;
        int health_;
        bool is_appeared_;
        SDL_Rect *draw_rect_;
        void drawHealth() {
            static int tw, th, draw_rect_width;
            static int draw_rect_height = BSD::HEALTH_DRAW_RECT_HEIGHT;
            auto health_texture
                    = SDL_helper::myCreateBlackStrTexture(
                            GD::g_font,
                            std::to_string(health_));
            SDL_QueryTexture(health_texture, nullptr, nullptr, &tw, &th);
            draw_rect_width
                    = static_cast<int>(1.0 * draw_rect_height * tw / th);
            SDL_Rect health_draw_rect
                    = (SDL_Rect) {
                            GD::WINDOW_WIDTH * 5 / 6 - (GD::WINDOW_WIDTH / 6 - draw_rect_width) / 2 - draw_rect_width,
                            GD::WINDOW_HEIGHT - 121,
                            draw_rect_width,
                            draw_rect_height
                    };
            SDL_RenderCopy(GameDefs::g_sdl_renderer, health_texture, nullptr, &health_draw_rect);
            if (health_texture) {
                SDL_DestroyTexture(health_texture);
            }
        }
    };
}

#endif //HUMANITY_BATTLESCENE_CHARACTER_ENEMY_ENEMY_H

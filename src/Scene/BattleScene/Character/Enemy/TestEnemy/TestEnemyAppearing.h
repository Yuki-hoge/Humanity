//
// Created by Y.A. on 2017/08/11.
//

#ifndef HUMANITY_BATTLESCENE_CHARACTER_ENEMY_TESTENEMY_TESTENEMYAPPEARING_H
#define HUMANITY_BATTLESCENE_CHARACTER_ENEMY_TESTENEMY_TESTENEMYAPPEARING_H

#include <vector>
#include "../EnemyStatus.h"
#include "SDL2/SDL_image.h"

class SDL_Texture;
class Mix_Chunk;

namespace BattleScene::Character::Enemy::TestEnemy {
    class TestEnemyAppearing : public EnemyStatus {
    public:
        void initialize() override;
        void update() override;
        void draw() override;

    private:
        SDL_Rect current_img_rect_;
        std::vector<SDL_Rect> img_rects_;
    };
}


#endif //HUMANITY_BATTLESCENE_CHARACTER_ENEMY_TESTENEMY_TESTENEMYAPPEARING_H

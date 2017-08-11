//
// Created by Y.A. on 2017/08/11.
//

#ifndef HUMANITY_APPEARING_H
#define HUMANITY_APPEARING_H

#include <vector>
#include "../../EnemyStatus.h"
#include "SDL2/SDL_image.h"

class SDL_Texture;
class Mix_Chunk;

namespace BattleScene::Character::Enemy::TestEnemy::Status {
    class Appearing : public EnemyStatus {
    public:
        void initialize() override;
        void update() override;
        void draw() override;
        void finalize() override;
        bool isDone() override;

    private:
        SDL_Texture *appearing_img_;
        SDL_Rect img_rect_;
        std::vector<SDL_Rect> img_rects_;
        Mix_Chunk *appearing_se_;
        int img_width_;
        int img_height_;

    };
}


#endif //HUMANITY_APPEARING_H

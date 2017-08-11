//
// Created by Y.A. on 2017/08/10.
//

#ifndef HUMANITY_NEUTRAL_H
#define HUMANITY_NEUTRAL_H

#include "../../EnemyStatus.h"

class SDL_Texture;

namespace BattleScene::Character::Enemy::TestEnemy::Status {
    class Neutral : public EnemyStatus {
    public:
        void initialize() override;
        void update() override;
        void draw() override;
        void finalize() override;
        bool isDone() override;

    private:
        SDL_Texture *neutral_img_;
    };
}


#endif //HUMANITY_NEUTRAL_H

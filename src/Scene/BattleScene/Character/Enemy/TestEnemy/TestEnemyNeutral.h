//
// Created by Y.A. on 2017/08/10.
//

#ifndef HUMANITY_BATTLESCENE_CHARACTER_ENEMY_TESTENEMY_TESTENEMYNEUTRAL_H
#define HUMANITY_BATTLESCENE_CHARACTER_ENEMY_TESTENEMY_TESTENEMYNEUTRAL_H

#include "../EnemyStatus.h"

class SDL_Texture;

namespace BattleScene::Character::Enemy::TestEnemy {
    class TestEnemyNeutral : public EnemyStatus {
    public:
        void initialize() override;
        void update() override;
        void draw() override;
    };
}


#endif //HUMANITY_BATTLESCENE_CHARACTER_ENEMY_TESTENEMY_TESTENEMYNEUTRAL_H

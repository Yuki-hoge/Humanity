//
// Created by Y.A. on 2017/08/01.
//

#ifndef HUMANITY_BATTLESCENE_CHARACTER_H
#define HUMANITY_BATTLESCENE_CHARACTER_H


namespace BattleScene::Character {
    class Status;
}

namespace BattleScene {
    namespace Character {
        class Character {
        public:
            virtual void initialize() = 0;

            virtual void update() = 0;

            virtual void draw() = 0;

            virtual void hit(int damage);

        protected:
            Status *current_status_;
            int health;
        };
    }
}

#endif //HUMANITY_BATTLESCENE_CHARACTER_H

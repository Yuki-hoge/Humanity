//
// Created by Y.A. on 2017/08/01.
//

#ifndef HUMANITY_BATTLESCENE_CHARACTER_H
#define HUMANITY_BATTLESCENE_CHARACTER_H

namespace BattleScene {
    class Character {
    public:
        virtual void update() = 0;
        virtual void draw() = 0;

    };
}

#endif //HUMANITY_BATTLESCENE_CHARACTER_H

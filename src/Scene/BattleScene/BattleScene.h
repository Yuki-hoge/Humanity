//
// Created by Y.A. on 2017/07/13.
//

#ifndef HUMANITY_BATTLESCENE_H
#define HUMANITY_BATTLESCENE_H


#include <SDL2/SDL_mixer.h>
#include "../Scene.h"

class SDL_Texture;

namespace BattleScene {
    class BattleScene : public Scene {
    public:
        void initialize() override;
        SceneExitStatus play() override;
        void finalize() override;
        static void drawBackGround();

    private:
        void update() override;
        void show() override;
        void playBeginningPart();
        void playEnemyEmergingPart();

        Mix_Music *battle_bgm_;
    };
}


#endif //HUMANITY_BATTLESCENE_H

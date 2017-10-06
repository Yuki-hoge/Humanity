//
// Created by Y.A. on 2017/07/13.
//

#ifndef HUMANITY_TITLESCENE_H
#define HUMANITY_TITLESCENE_H

#include "../Scene.h"
#include <SDL2/SDL_mixer.h>

class TitleMessage;
class SDL_Texture;
//class Mix_Music;

class TitleScene : public Scene {
private:
    enum class PartExitStatus : int {
        QUIT,
        CONTINUE,
    };
    enum class UserInputKey : int {
        NONE,
        ESC_QUIT,
        ELSE,
    };
    UserInputKey checkUserInputKey();

public:
    void initialize();
    SceneExitStatus play();
    void finalize();

//    for singleton pattern
    static TitleScene *getInstancePtr() {
        if (!instance_ptr) {
            instance_ptr = new TitleScene();
        }
        return instance_ptr;
    }
    TitleScene(const TitleScene&) = delete;
    TitleScene& operator=(const TitleScene&) = delete;
    TitleScene(TitleScene&&) = delete;
    TitleScene& operator=(TitleScene&&) = delete;

private:
    TitleScene() = default;
    ~TitleScene() = default;
    void show();
    void drawBackground();
    void drawMessage();
    void drawStaticMessage();
    void showBlackout();

    // sceneは各パートに分割され，playHogehogePart()で再生
    void playBeginningPart();
    PartExitStatus playInputWaitingPart();
    void playFinishingPart();

    static TitleScene *instance_ptr;
    TitleMessage *title_message_;
    SDL_Texture *title_logo_;
    Mix_Music *title_bgm_;
    Mix_Chunk *chunk_se_;
};


#endif //HUMANITY_TITLESCENE_H

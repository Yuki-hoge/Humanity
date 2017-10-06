//
// Created by Y.A. on 2017/07/13.
//

#define TITLE_LOGO_DRAW_WIDTH 500
#define TITLE_LOGO_DRAW_HEIGHT 125

#include "TitleScene.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "TitleMessage.h"
#include "../../GameDefs.h"
#include "../../tools/Timer.h"
#include "../../tools/SDL_helper.h"

using namespace GameDefs;

//for singleton pattern
TitleScene* TitleScene::instance_ptr = nullptr;

void TitleScene::initialize() {
    title_message_ = new TitleMessage();
    title_message_->initialize();

    title_logo_
            = SDL_helper::myCreateTextureFromIMG(g_sdl_renderer, "data/title_scene/title_logo.png");

    title_bgm_ = SDL_helper::myLoadMUS("data/sound/title_scene/title_bgm.wav");
    chunk_se_ = SDL_helper::myLoadWAV("data/sound/title_scene/se.wav");
}

SceneExitStatus TitleScene::play() {
    Mix_PlayMusic(title_bgm_, -1);
    playBeginningPart();
    switch (playInputWaitingPart()) {
        case PartExitStatus::QUIT:
            return SceneExitStatus::QUIT;
        default:
            break;
    }

    playFinishingPart();
    return SceneExitStatus::CONTINUE;
}

void TitleScene::finalize() {
    delete title_message_;
    title_message_ = nullptr;
    if (instance_ptr) {
        delete instance_ptr;
        instance_ptr = nullptr;
    }

    SDL_DestroyTexture(title_logo_); title_logo_ = nullptr;
    Mix_FreeMusic(title_bgm_); title_bgm_ = nullptr;
    if (!chunk_se_) {
        Mix_FreeChunk(chunk_se_);
        chunk_se_ = nullptr;
    }
}

TitleScene::UserInputKey TitleScene::checkUserInputKey() {
    SDL_Event event; int key;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return UserInputKey::ESC_QUIT;
            case SDL_KEYDOWN:
                key = event.key.keysym.sym;
                if (key == SDLK_ESCAPE) {
                    return UserInputKey::ESC_QUIT;
                } else {
                    return UserInputKey::ELSE;
                }
            default:
                // do nothing
                break;
        }
    }
    return UserInputKey::NONE;
}

void TitleScene::show() {
    drawBackground();
    drawMessage();
    SDL_RenderPresent(g_sdl_renderer); // Show sdl_renderer on window
}

void TitleScene::drawBackground() {
    static SDL_Rect draw_rect = (SDL_Rect){70,50,TITLE_LOGO_DRAW_WIDTH,TITLE_LOGO_DRAW_HEIGHT};

    // Set sdl_renderer draw color to white
    SDL_SetRenderDrawColor(g_sdl_renderer, DRAW_COLOR_WHITE);
    // Fill sdl_renderer with color
    SDL_RenderClear(g_sdl_renderer);

    SDL_RenderCopy(g_sdl_renderer, title_logo_, nullptr, &draw_rect);
}

void TitleScene::drawMessage() {
    title_message_->draw();
}

void TitleScene::playBeginningPart() {
    drawBackground();
    SDL_RenderPresent(g_sdl_renderer); // Show sdl_renderer on window
    SDL_Delay(2500);
}

TitleScene::PartExitStatus TitleScene::playInputWaitingPart() {
    Timer timer;
    UserInputKey uik;
    while (true) {
        timer.restart();
        uik = checkUserInputKey();
        switch (uik) {
            case UserInputKey::ESC_QUIT:
                // if input key is esc, then quit game
//                show_quit_animation();
                return PartExitStatus::QUIT;
            case UserInputKey::ELSE:
                // game will be continued to next scene...
                return PartExitStatus::CONTINUE;
            default:
                break;
        }

        // update title element
        title_message_->update();

        auto elapsed_usec = timer.getElapsedNanosec();
        if (elapsed_usec < FRAME_INTERVAL_US) {
            timer.sleepNanosec(FRAME_INTERVAL_US - elapsed_usec);
        } else {
            timer.sleepNanosec(2*FRAME_INTERVAL_US - elapsed_usec);
        }
        show();
    }
}

void TitleScene::playFinishingPart() {
    Mix_HaltMusic();
    Mix_PlayChannel(-1, chunk_se_, 0);
    showBlackout();
    SDL_Delay(800);
}

void TitleScene::drawStaticMessage() {
    title_message_->drawStaticMessage();
}

void TitleScene::showBlackout() {
    static SDL_Rect draw_rect = (SDL_Rect){0,0,GameDefs::WINDOW_WIDTH,GameDefs::WINDOW_HEIGHT};
    static SDL_Texture *blackout_img
            = SDL_helper::myCreateTextureFromIMG(g_sdl_renderer, "data/blackout.png");
    static int mini_img_width = GameDefs::WINDOW_WIDTH/5;
    static int mini_img_height = GameDefs::WINDOW_HEIGHT/5;

    static std::vector<SDL_Rect> img_rects = {
            (SDL_Rect){mini_img_width*0,0,mini_img_height,mini_img_width},
            (SDL_Rect){mini_img_width*1,0,mini_img_height,mini_img_width},
            (SDL_Rect){mini_img_width*2,0,mini_img_height,mini_img_width},
            (SDL_Rect){mini_img_width*3,0,mini_img_height,mini_img_width},
            (SDL_Rect){mini_img_width*4,0,mini_img_height,mini_img_width},
            (SDL_Rect){mini_img_width*5,0,mini_img_height,mini_img_width},
    };

    // blackout.png を左から切り替えて表示していくことで暗転を表現
    for (const auto& img_rect : img_rects) {
        drawBackground();
        drawStaticMessage();
        SDL_RenderCopy(g_sdl_renderer, blackout_img, &img_rect, &draw_rect);
        SDL_RenderPresent(g_sdl_renderer); // Show sdl_renderer on window
        SDL_Delay(100);
    }
}

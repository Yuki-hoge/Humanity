//
// Created by Y.A. on 2017/07/13.
//

#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "GameDefs.h"
#include "Scene/TitleScene/TitleScene.h"
#include "Scene/BattleScene/BattleScene.h"
#include "Scene/SceneExitStatus.h"

using namespace GameDefs;

void Game::initialize() {
    // Starting SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // initializing SDL_mixer
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
        std::cout << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
        exit(1);
    }
//    initialize window and renderer
    initializeSDLWindow();
    initializeSDLRenderer();

//    initialize title scene
    title_scene_ = TitleScene::getInstancePtr();
    title_scene_->initialize();
}

void Game::run() {
    SceneExitStatus scene_exit_status;

//    play title scene
    scene_exit_status = title_scene_->play();
    if (scene_exit_status == SceneExitStatus::QUIT) return;


    current_scene_ = new BattleScene::BattleScene();
    current_scene_->initialize();
    current_scene_->play();
}

void Game::finalize() {
//    Free game objects
    title_scene_->finalize(); //delete title_scene_;
    current_scene_->finalize(); delete current_scene_;
    SDL_DestroyRenderer(g_sdl_renderer);
    SDL_DestroyWindow(sdl_window_);
    sdl_window_ = nullptr; g_sdl_renderer = nullptr;

    // finalizing SDL_mixer
    Mix_CloseAudio();

//    Quit program
    SDL_Quit();
}

void Game::initializeSDLWindow() {
//    Create a Window
    sdl_window_ = SDL_CreateWindow("Humanity.out",
                                   WINDOW_POSITION_X, WINDOW_POSITION_Y,
                                   WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (sdl_window_ == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Game::initializeSDLRenderer() {
//    Create a Renderer
    GameDefs::g_sdl_renderer = SDL_CreateRenderer(sdl_window_, -1,
                                       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (GameDefs::g_sdl_renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

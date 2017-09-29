//
// Created by Y.A. on 2017/07/13.
//

#ifndef HUMANITY_GAME_H
#define HUMANITY_GAME_H


class SDL_Window;
class SDL_Renderer;
class UserInputHandler;
class EventHandler;
class Scene;
class TitleScene;


class Game {
public:
    ~Game() {
        finalize();
    }
    void initialize();
    void run();
    void finalize();

private:
    SDL_Window *sdl_window_;
//    SDL_Renderer *sdl_renderer_;
//    UserInputHandler *user_input_handler_;
//    EventHandler *event_handler_;
    Scene *current_scene_;
    TitleScene *title_scene_;

    void initializeSDLWindow();
    void initializeSDLRenderer();
    void initializeTTFFont();
};


#endif //HUMANITY_GAME_H

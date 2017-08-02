//
// Created by Y.A. on 2017/07/15.
//

#ifndef HUMANITY_TITLEMESSAGE_H
#define HUMANITY_TITLEMESSAGE_H


#include <SDL2/SDL_surface.h>
#include <string>
#include <vector>

class SDL_Renderer;
class SDL_Texture;
class SDL_Rect;

class TitleMessage {
public:
    ~TitleMessage() {
        finalize();
    }
    void initialize();
    void update();
    void draw();
    void drawStaticMessage();

private:
    void finalize();
    std::vector<SDL_Texture*> msg_textures_;
    SDL_Texture *current_msg_texture_;
};


#endif //HUMANITY_TITLEMESSAGE_H

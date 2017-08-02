//
// Created by Y.A. on 2017/07/21.
//

#ifndef HUMANITY_SDL_HELPER_H
#define HUMANITY_SDL_HELPER_H


#include <string>
#include <SDL2/SDL_mixer.h>

class SDL_Renderer;
class SDL_Surface;
class SDL_Texture;
//class Mix_Music;
//class Mix_Chunk;

namespace SDL_helper {
    SDL_Surface* myIMGLoad(std::string img_path);
    SDL_Texture* myCreateTextureFromIMG(SDL_Renderer *renderer, std::string img_path);
    Mix_Music* myLoadMUS(std::string music_path);
    Mix_Chunk* myLoadWAV(std::string music_path);
    void drawWhiteBack(SDL_Renderer *renderer);
};


#endif //HUMANITY_SDL_HELPER_H

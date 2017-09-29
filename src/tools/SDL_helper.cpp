//
// Created by Y.A. on 2017/07/21.
//

#include "SDL_helper.h"
#include <iostream>
//#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../GameDefs.h"

SDL_Surface* ::SDL_helper::myIMGLoad(std::string img_path) {
    SDL_Surface *img = IMG_Load(img_path.c_str());
    if (img == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    return img;
}

SDL_Texture* ::SDL_helper::myCreateTextureFromIMG(SDL_Renderer *renderer, std::string img_path) {
    if (img_path == "blank") {
        return SDL_CreateTextureFromSurface(renderer, nullptr);
    }

    SDL_Surface *surface = myIMGLoad(img_path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}


Mix_Music* ::SDL_helper::myLoadMUS(std::string music_path) {
    Mix_Music *music = Mix_LoadMUS(music_path.c_str());
    if(!music) {
        std::cout << "Mix_LoadMUS Error: " << Mix_GetError() << std::endl;
        exit(1);
    }

    return music;
}

Mix_Chunk* ::SDL_helper::myLoadWAV(std::string music_path) {
    Mix_Chunk *chunk = Mix_LoadWAV(music_path.c_str());
    if (!chunk) {
        std::cout << "Mix_LoadWAV Error: " << Mix_GetError() << std::endl;
        exit(1);
    }

    return chunk;
}

void ::SDL_helper::drawWhiteBack(SDL_Renderer *renderer) {
    // Set sdl_renderer draw color to white
    SDL_SetRenderDrawColor(renderer, DRAW_COLOR_WHITE);
    // Fill sdl_renderer with color
    SDL_RenderClear(renderer);
}

TTF_Font* ::SDL_helper::myOpenFont(int ptsize) {
    TTF_Font *font = TTF_OpenFont("data/font.ttf", ptsize);
    if (!font) {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        exit(1);
    }
    return font;
}


SDL_Texture* ::SDL_helper::myCreateBlackStrTexture(TTF_Font *font, std::string string) {
    static SDL_Color color_fg = {DRAW_COLOR_BLACK};
    static SDL_Color color_bg = {DRAW_COLOR_WHITE};

    auto surface = TTF_RenderUTF8_Shaded(font, string.c_str(), color_fg, color_bg);
    auto texture = SDL_CreateTextureFromSurface(GameDefs::g_sdl_renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}


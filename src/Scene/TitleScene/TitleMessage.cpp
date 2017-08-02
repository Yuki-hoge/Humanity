//
// Created by Y.A. on 2017/07/15.
//

#include "TitleMessage.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../../tools/SDL_helper.h"
#include "../../GameDefs.h"

using namespace GameDefs;

// title msgの素材読み込み
void TitleMessage::initialize() {
    std::vector<std::string> img_paths;
    img_paths.push_back("data/title_scene/title_message/msg1.png");
    img_paths.push_back("data/title_scene/title_message/msg2.png");
    img_paths.push_back("blank");

    for (const auto& path : img_paths) {
        msg_textures_.push_back(SDL_helper::myCreateTextureFromIMG(g_sdl_renderer, path));
    }
}

void TitleMessage::update() {
    static int active_frame_long = 30;
    static int active_frame_short = 5;
    static int end_idx = static_cast<int>(msg_textures_.size() - 1);
    static int current_texture_idx = 0;
    static int delta_idx = 1;
    static int remaining_frame = active_frame_long;

    remaining_frame--;
    if (remaining_frame < 0) {
        int new_idx = current_texture_idx + delta_idx;
        current_msg_texture_ = msg_textures_[new_idx];

        if (new_idx == 0) {
            delta_idx = 1;
            remaining_frame = active_frame_long;
        } else if (new_idx == end_idx) {
            delta_idx = -1;
            remaining_frame = active_frame_long;
        } else {
            remaining_frame = active_frame_short;
        }
        current_texture_idx = new_idx;
    }
}

void TitleMessage::draw() {
    static SDL_Rect draw_rect = (SDL_Rect){170,350,300,50};
    SDL_RenderCopy(g_sdl_renderer, current_msg_texture_, nullptr, &draw_rect);
}

void TitleMessage::finalize() {
    for (const auto& msg_texture : msg_textures_) {
        SDL_DestroyTexture(msg_texture);
    }
    msg_textures_.clear();
}

void TitleMessage::drawStaticMessage() {
    static SDL_Rect draw_rect = (SDL_Rect){170,350,300,50};
    SDL_RenderCopy(g_sdl_renderer, msg_textures_[0], nullptr, &draw_rect);
}


//
// Created by Y.A. on 2017/08/01.
//

#include "GameDefs.h"

namespace GameDefs {
    int WINDOW_WIDTH = 640;
    int WINDOW_HEIGHT = 480;
    int WINDOW_POSITION_X = 100;
    int WINDOW_POSITION_Y = 100;
    int FRAMES_PER_SECOND = 60;
    int FRAME_INTERVAL_US = 1000000/FRAMES_PER_SECOND;
    SDL_Renderer *g_sdl_renderer = nullptr;
    TTF_Font *g_font = nullptr;
    int FONT_SIZE = 30;
}
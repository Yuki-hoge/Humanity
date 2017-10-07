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
    long FRAME_INTERVAL_NS = 1000000000/FRAMES_PER_SECOND;
    SDL_Renderer *g_sdl_renderer = nullptr;
    TTF_Font *g_font = nullptr;
    int FONT_SIZE = 30;
}
//
// Created by Y.A. on 2017/08/01.
//

#include "GameDefs.h"

namespace GameDefs {
    int WINDOW_WIDTH = 640;
    int WINDOW_HEIGHT = 480;
    int WINDOW_POSITION_X = 100;
    int WINDOW_POSITION_Y = 100;
    int FRAME_INTERVAL_US = 1000000/60;
    int TOTAL_ENEMY_APPEARANCE_FRAMES = 12;
    SDL_Renderer *g_sdl_renderer = nullptr;
}
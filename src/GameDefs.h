//
// Created by Y.A. on 2017/07/13.
//

#ifndef HUMANITY_GAMEDEFS_H
#define HUMANITY_GAMEDEFS_H

//#define WINDOW_WIDTH 640
//#define WINDOW_HEIGHT 480
//#define WINDOW_POSITION_X 100
//#define WINDOW_POSITION_Y 100
//#define FRAME_INTERVAL_US (1000000 / 60)


#define DRAW_COLOR_WHITE 255, 255, 255, 255
#define DRAW_COLOR_BLACK 0, 0, 0, 255

class SDL_Renderer;

namespace GameDefs {
    extern int WINDOW_WIDTH;
    extern int WINDOW_HEIGHT;
    extern int WINDOW_POSITION_X;
    extern int WINDOW_POSITION_Y;
    extern int FRAME_INTERVAL_US;
    extern int TOTAL_ENEMY_APPEARANCE_FRAMES;
    extern SDL_Renderer *g_sdl_renderer;
}

#endif //HUMANITY_GAMEDEFS_H

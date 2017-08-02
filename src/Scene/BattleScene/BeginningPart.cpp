//
// Created by Y.A. on 2017/08/01.
//

#include "BeginningPart.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "../../tools/SDL_helper.h"
#include "../../GameDefs.h"
#include "../PartExitStatus.h"

using namespace GameDefs;

namespace BattleScene {
    PartExitStatus BeginningPart::play() {
        Mix_Chunk *se = SDL_helper::myLoadWAV("data/sound/battle_scene/beginning_part_se.wav");
        SDL_helper::drawWhiteBack(g_sdl_renderer);
        SDL_RenderPresent(g_sdl_renderer); // Show sdl_renderer on window
        Mix_PlayChannel(-1, se, 0);

        SDL_Delay(2500);
        Mix_FreeChunk(se);
        return PartExitStatus::CONTINUE;
    }

    void BeginningPart::update() {

    }

    void BeginningPart::show() {

    }
}
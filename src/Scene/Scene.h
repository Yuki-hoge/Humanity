//
// Created by Y.A. on 2017/07/13.
//

#ifndef HUMANITY_SCENE_H
#define HUMANITY_SCENE_H

#include "SceneExitStatus.h"


class SDL_Renderer;

class Scene {
public:
    virtual ~Scene(){};
    virtual void initialize(){};
    virtual SceneExitStatus play() = 0;
    virtual void finalize() = 0;
};


#endif //HUMANITY_SCENE_H

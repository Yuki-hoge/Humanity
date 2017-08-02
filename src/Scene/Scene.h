//
// Created by Y.A. on 2017/07/13.
//

#ifndef HUMANITY_SCENE_H
#define HUMANITY_SCENE_H

#include "SceneType.h"
#include "SceneExitStatus.h"


class SDL_Renderer;

class Scene {
public:
    virtual ~Scene(){};
    virtual void initialize() {
        scene_type_ = SceneType::NONE;
    };
    virtual SceneExitStatus play() = 0;
    virtual void finalize() = 0;

protected:
    virtual void update() = 0;
    virtual void show() = 0;
    SceneType scene_type_;
};


#endif //HUMANITY_SCENE_H

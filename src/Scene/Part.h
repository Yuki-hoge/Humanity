//
// Created by Y.A. on 2017/08/01.
//

#ifndef HUMANITY_PART_H
#define HUMANITY_PART_H

//#include "PartExitStatus.h"

class Timer;
class SDL_Renderer;
enum class PartExitStatus : int;

class Part {
public:
    virtual void initialize(){};
    virtual PartExitStatus play() = 0;
    virtual void finalize(){};

protected:
    virtual void update() = 0;
    virtual void show() = 0;
    void sleepAtMost2F(const Timer &timer);

};


#endif //HUMANITY_PART_H

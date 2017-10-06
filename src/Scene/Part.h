//
// Created by Y.A. on 2017/08/01.
//

#ifndef HUMANITY_PART_H
#define HUMANITY_PART_H

//#include "PartExitStatus.h"
#include "../GameDefs.h"
#include "../tools/Timer.h"

class Timer;
class SDL_Renderer;
enum class PartExitStatus : int;
namespace GD = GameDefs;

class Part {
public:
    virtual void initialize(){};
    virtual PartExitStatus play() = 0;
    virtual void finalize(){};

protected:
    virtual void update(){};
    virtual void show(){};
    inline void sleepAtMost2F(const Timer &timer) {
        auto elapsed_usec = timer.getElapsedNanosec();
        if (elapsed_usec < GD::FRAME_INTERVAL_US) {
            timer.sleepNanosec(GD::FRAME_INTERVAL_US - elapsed_usec);
        } else {
            timer.sleepNanosec(2 * GD::FRAME_INTERVAL_US - elapsed_usec);
        }
    };

};


#endif //HUMANITY_PART_H

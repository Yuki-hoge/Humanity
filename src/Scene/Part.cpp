//
// Created by Y.A. on 2017/08/01.
//

#include "Part.h"
#include "../tools/Timer.h"
#include "../GameDefs.h"

using namespace GameDefs;

void Part::sleepAtMost2F(const Timer &timer) {
    auto elapsed_usec = timer.getElapsedNanosec();
    if (elapsed_usec < FRAME_INTERVAL_US) {
        timer.sleepNanosec(FRAME_INTERVAL_US - elapsed_usec);
    } else {
        timer.sleepNanosec(2 * FRAME_INTERVAL_US - elapsed_usec);
    }
}

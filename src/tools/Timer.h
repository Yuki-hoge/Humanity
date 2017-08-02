//
// Created by Y.A. on 2016/09/18.
//

#ifndef HUMANITY_TIMER_H
#define HUMANITY_TIMER_H

#include <chrono>

class Timer {
public:
    Timer();
    void restart();
    long long getElapsedNanosec() const;
    void sleepNanosec(long ns) const;

private:
    std::chrono::high_resolution_clock::time_point start_;
};


#endif //HUMANITY_TIMER_H

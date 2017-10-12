//
// Created by Y.A. on 2016/09/18.
//

#include "Timer.h"

using namespace std::chrono;

Timer::Timer() {
    start_ = high_resolution_clock::now();
}

long Timer::getElapsedNanosec() const {
    auto end = high_resolution_clock::now();
    auto dur = end - start_;
    auto elapsed_nanosec = duration_cast<nanoseconds>(dur).count();
    return static_cast<long>(elapsed_nanosec);
}

void Timer::restart() {
    start_ = high_resolution_clock::now();
}

void Timer::sleepNanosec(long ns) const {
    struct timespec req = {NULL, ns};
    nanosleep(&req, nullptr);
}


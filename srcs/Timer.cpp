//
// Created by sauvau_m on 4/3/17.
//

#include "../include/Timer.hpp"

Timer::~Timer() {

}

Timer::Timer() {

}

void Timer::start() {
    epoch = std::chrono::steady_clock::now();
}

std::chrono::steady_clock::duration Timer::timeElapsed() const {
    return std::chrono::steady_clock::now() - epoch;
}

bool Timer::isTimeOverMilliseconds(size_t milliseconds) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(timeElapsed()).count() >= milliseconds;
}

bool Timer::isTimeOverSeconds(size_t seconds) {
    return std::chrono::duration_cast<std::chrono::seconds>(timeElapsed()).count() >= seconds;
}


//
// Created by sauvau_m on 4/3/17.
//

#ifndef CPP_ARCADE_TIMER_HPP
#define CPP_ARCADE_TIMER_HPP


#include <chrono>

class Timer {

    std::chrono::steady_clock::time_point epoch;

public:
    virtual ~Timer();
    Timer();
    void start();
    std::chrono::steady_clock::duration timeElapsed() const;
    bool isTimeOverMilliseconds(int milliseconds);
    bool isTimeOverSeconds(int seconds);
};


#endif //CPP_ARCADE_TIMER_HPP

#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>
#include <SFML/System.hpp>
#include "Global.h"

using namespace std::chrono;

static SizeT /* milliseconds */ time_now()
{
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

class Clock
{
public:
    inline float get_delta_time() { return m_clock.restart().asSeconds(); }

private:
    sf::Clock m_clock;
};

struct Timer
{
    SizeT sys_time;
    SizeT interval;
    bool  repeat;
};

#endif // CLOCK_H

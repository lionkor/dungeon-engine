#ifndef APPLICATION_H
#define APPLICATION_H

#include "Global.h"
#include "State.h"
#include "ECS/Entity.h"
#include "Clock.h"

enum class ShutdownHint
{
    WindowClosed  = 0, // Window closing using [x]
    GameExit      = 1, // Game exiting using ingame menu / hotkey
    CriticalAbort = 2, // Generic super bad failure :(
};

class Application
{
public:
    void shutdown(ShutdownHint);
    void run();

    State&       state();
    const State& state() const;

    void register_timer(SizeT interval_ms, bool repeat, std::function<void()> fnc);

    float delta_time();

    // FIXME: This will always be SFML
    static constexpr BackendImplementation backend_implementation =
        BackendImplementation::SFML;

protected:
    void update_timers();

    Application();

    OwnPtr<State> m_current_state;
    bool          m_is_running;
    float         m_dt;

    Vector<std::pair<Timer, std::function<void()>>> m_timers;

    // Singleton
public:
    static Application& the();

protected:
    static OwnPtr<Application> s_the_application;
};

#endif // APPLICATION_H

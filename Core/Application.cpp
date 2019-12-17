#include "Application.h"
#include "GameState.h"
#include "Global.h"
#include "Window.h"
#include "Clock.h"
#include <chrono>

OwnPtr<Application> Application::s_the_application;

void Application::shutdown(ShutdownHint hint)
{
    LOG("Shutting down (" << static_cast<int>(hint) << ")");
    Window::the().backend().close_window();
    m_is_running = false;
}

void Application::run()
{
    m_is_running = true;

    Clock clock;

    register_timer(500, true, [&]() {
        Window::the().set_title(String::format(
            "Window | ", static_cast<int>(1.0f / Application::the().delta_time())));
    });

    while (m_is_running)
    {
        ASSERT(m_current_state.is_not_null());

        // FIXME: delta time
        m_dt = clock.get_delta_time();

        Window::the().update(m_dt);
        m_current_state->update(m_dt);

        update_timers();

        Window::the().draw();
    }
}

float Application::delta_time()
{
    return m_dt;
}

State& Application::state()
{
    return *m_current_state;
}

const State& Application::state() const
{
    return *m_current_state;
}

void Application::register_timer(SizeT interval, bool repeat, std::function<void()> fnc)
{
    Timer t;
    t.sys_time = time_now();
    t.interval = interval;
    t.repeat   = repeat;
    m_timers.push_back({ t, fnc });
}

void Application::update_timers()
{
    // FIXME this is ugly.
    SizeT time = time_now();
    for (auto& pair : m_timers)
    {
        if (time >= pair.first.sys_time + pair.first.interval)
        {
            pair.second();
            if (!pair.first.repeat)
                pair.first.sys_time = 0;
            else
                pair.first.sys_time += pair.first.interval;
        }
    }

    m_timers = Vector<std::pair<Timer, std::function<void()>>>(
        m_timers.begin(),
        std::remove_if(m_timers.begin(), m_timers.end(),
                       [&](const auto& v) { return v.first.sys_time == 0; }));
}

Application& Application::the()
{
    if (!Application::s_the_application)
    {
        Application::s_the_application = OwnPtr<Application>(new Application());
    }
    return *Application::s_the_application;
}

Application::Application() : m_current_state(GameState::construct()), m_is_running(false)
{
    // FIXME: Do we need to create the window here like this ???
    Window::the();
}

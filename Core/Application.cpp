#include "Application.h"
#include "GameState.h"
#include "Window.h"

OwnPtr<Application> Application::s_the_application;

void Application::shutdown()
{
    m_is_running = false;
}

void Application::run()
{
    m_is_running = true;

    while (m_is_running)
    {
        ASSERT(m_current_state.is_not_null());

        // FIXME: delta time

        Window::the().update(0);
        m_current_state->update(0);

        Window::the().draw();
    }
}

State& Application::state()
{
    return *m_current_state;
}

const State& Application::state() const
{
    return *m_current_state;
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

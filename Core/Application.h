#ifndef APPLICATION_H
#define APPLICATION_H

#include "Global.h"
#include "State.h"
#include "ECS/Entity.h"

class Application
{
public:
    // FIXME: add a reason / error code?
    void shutdown();
    void run();

    State&       state();
    const State& state() const;

    // FIXME: This will always be SFML
    static constexpr BackendImplementation backend_implementation =
        BackendImplementation::SFML;

protected:
    Application();

    OwnPtr<State> m_current_state;
    bool          m_is_running;

    // Singleton
public:
    static Application& the();

protected:
    static OwnPtr<Application> s_the_application;
};

#endif // APPLICATION_H

#ifndef STATE_H
#define STATE_H

#include "Global.h"
#include "ECS/Entity.h"

class Application;
class Window;
class Renderer;

class State
{
public:
    State(Application& application) : m_application(application), m_entities(0) {}
    virtual ~State() {}

    virtual void update(float dt) = 0;

    Application& application();
    const Application& application() const;

    Window& window();
    const Window& window() const;

    Renderer& renderer();
    const Renderer& renderer() const;

    template<typename _EntityT, typename... _Args>
    void adopt_entity(_Args&&... args)
    {
        auto e = _EntityT::construct(*this, std::forward(args)...);
        m_entities.emplace(std::pair { e->int_guid(), std::move(e) });
    }
    RawPtr<Entity> get_entity(GUID guid);

protected:
    Application& m_application;
    UnorderedMap<ptr_t, OwnPtr<Entity>> m_entities;
};

#endif // STATE_H

#ifndef STATE_H
#define STATE_H

#include "Global.h"
#include "ECS/Entity.h"

class Application;

class State
{
public:
    State(Application& application) : m_application(application), m_entities(0) {}
    virtual ~State() {}

    virtual void update(float dt) = 0;

    Application& application();
    const Application& application() const;

    void adopt_entity(OwnPtr<Entity>&& ptr);
    RawPtr<Entity> get_entity(GUID guid);

protected:
    Application& m_application;
    UnorderedMap<ptr_t, OwnPtr<Entity>> m_entities;
};

#endif // STATE_H

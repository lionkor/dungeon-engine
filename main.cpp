#include "Core/Global.h"
#include "Core/Application.h"
#include "Core/GameState.h"

class Person : public Entity
{
    OBJECT_CAST_CTOR(Person, Entity, override);
public:
    
    virtual void update(float) override 
    {
        if (m_state.window().is_key_pressed(Key::B))
            std::cout << "B IS PRESSED!" << std::endl;
    }
    
    // Serializable interface
public:
    virtual void serialize(File&) override {}
    virtual void deserialize(File&) override {}
    
protected:
    Person(State& e) : Entity(e) {}
};

int main(int, char**)
{
    auto app = Application::construct(BackendImplementation::SFML);
    
    reinterpret_cast<GameState&>(app->state()).adopt_entity<Person>();
    
    app->run();
}


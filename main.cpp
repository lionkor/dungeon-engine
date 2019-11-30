#include "Core/Global.h"
#include "Core/Application.h"
#include "Core/GameState.h"
#include "Core/ECS/SpriteRenderComponent.h"

class Person : public Entity
{
    OBJECT_CAST_CTOR(Person, Entity, override);

public:
    virtual void update(float) override
    {
        if (m_state.window().is_key_pressed(Key::B))
            std::cout << "B IS PRESSED!" << std::endl;
    }

    virtual void serialize(File&) override {}
    virtual void deserialize(File&) override {}

protected:
    Person(State& e) : Entity(e)
    {
        auto& spritecomp = add_component<SpriteRenderComponent>();
        spritecomp.set_sprite(
            Sprite(m_state.renderer().create_material(nullptr, Color { 255, 0, 0, 0 }),
                   Rectangle { {
                                   0,
                                   0,
                               },
                               { 100, 100 } }));
    }
};

int main(int, char**)
{
    auto app = Application::construct(BackendImplementation::SFML);

    reinterpret_cast<GameState&>(app->state()).adopt_entity<Person>();

    app->run();
}

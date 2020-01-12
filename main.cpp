#include "Core/Global.h"
#include "Core/Application.h"
#include "Core/GameState.h"
#include "Core/Window.h"
#include "Core/ECS/SpriteRenderComponent.h"

class Person : public Entity {
    OBJECT_CAST_CTOR(Person, Entity, override);

public:
    virtual void update(float) override
    {
        if (Window::the().is_key_pressed(Key::B))
            std::cout << "B IS PRESSED!" << std::endl;
    }

    virtual void serialize(File&) override {}
    virtual void deserialize(File&) override {}

protected:
    Person(State& e) : Entity(e, vec2 { 300, 300 })
    {
        add_component<SpriteRenderComponent>(
            Sprite(Path("res/textures/ground.png"), "simple", Rectangle({ 0, 0 }, { 100, 100 })));
    }
};


int main(int, char**)
{
    auto& app = Application::the();

    reinterpret_cast<GameState&>(app.state()).adopt_entity<Person>();
    app.run();
}

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
        if (Window::the().is_key_pressed(Key::B))
            std::cout << "B IS PRESSED!" << std::endl;
    }

    virtual void serialize(File&) override {}
    virtual void deserialize(File&) override {}

protected:
    Person(State& e) : Entity(e, vec2 { 300, 300 })
    {
        auto& c = add_component<SpriteRenderComponent>();
        c.set_sprite(Sprite(Material(Texture("/home/lion/src/games/dungeon/res/textures/wall.png"_sv), Color()), Rectangle(m_transform.position(), { 100, 100 })));
    }
};

int main(int, char**)
{
    auto& app = Application::the();

    reinterpret_cast<GameState&>(app.state()).adopt_entity<Person>();

    app.run();
}

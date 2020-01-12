#include "acutest/include/acutest.h"
#include "../Core/Global.h"
#include "../Core/Memory.h"            // RefPtr
#include "../Core/GUID.h"              // GUID
#include "../Core/IO/File.h"           // ImageFile
#include "../Core/IO/Path.h"           // Path
#include "../Core/Clock.h"             // Clock
#include "../Core/ECS/Entity.h"        // Entity
#include "../Core/State.h"             // State
#include "../Core/Rendering/Texture.h" // Texture
#include <functional>
#include <unistd.h>

class GUIDTestObject : public GUID
{
};

void class_ImageFile(void) {
    {
        TEST_CASE("rainbow.jpg");
        Path      path("res/textures/rainbow.jpg");
        ImageFile file(path);

        auto tex = file.create_texture();
        TEST_CHECK(tex.is_not_null());
        // this image should be 1300x1300 pixels

        if (!TEST_CHECK(tex->width() == 1300)) {
            TEST_MSG("Expected 1300, got %d", tex->width());
        }

        if (!TEST_CHECK(tex->height() == 1300)) {
            TEST_MSG("Expected 1300, got %d", tex->height());
        }
    }
    {
        TEST_CASE("ground.png");
        Path      path("res/textures/ground.png");
        ImageFile file(path);

        auto tex = file.create_texture();
        TEST_CHECK(tex.is_not_null());

        // this image should be 10x10 pixels
        if (!TEST_CHECK(tex->width() == 10)) {
            TEST_MSG("Expected 10, got %d", tex->width());
        }

        if (!TEST_CHECK(tex->height() == 10)) {
            TEST_MSG("Expected 10, got %d", tex->height());
        }
    }
}

void class_Clock(void) {
    Clock clock;
    clock.get_delta_time();
    sleep(1);
    float seconds = clock.get_delta_time();

    TEST_CHECK(seconds > 1.0f);
    TEST_CHECK(seconds < 1.1f);
    TEST_CHECK(time_now() != 0);
}

void class_RefPtr_basic_behv(void) {
    RefPtr<int> null_ptr(nullptr);

    TEST_CHECK(null_ptr.get() == nullptr);
    TEST_CHECK(null_ptr.is_not_null() == false);
    TEST_CHECK(null_ptr.is_null() == true);

    RefPtr<int> ptr(new int(5));

    TEST_CHECK(bool(ptr) == true);
    TEST_CHECK(ptr.get() != nullptr);
    TEST_CHECK(ptr.is_not_null() == true);
    TEST_CHECK(ptr.is_null() == false);
    TEST_CHECK(*ptr == 5);

    TEST_CHECK(ptr.as<long>() == 5l);
    TEST_CHECK(*ptr.as_ptr<long>() == 5l);
}

void class_GUID(void) {
    GUID g1;
    GUID g2;

    TEST_CHECK(g1 != g2);
    TEST_CHECK(g1 == g1);

    GUIDTestObject one;
    GUIDTestObject other;

    TEST_CHECK(one != other);
    TEST_CHECK(one.int_guid() != other.int_guid());
}

void sanity_checks(void) {
    TEST_CHECK(sizeof(int) == 4);
    TEST_CHECK(sizeof(long) == 8);
    TEST_CHECK(sizeof(float) == 4);
    TEST_CHECK(sizeof(double) == 8);
    TEST_CHECK(sizeof(char) == 1);
}

void class_State(void);
class TestState : public State
{
    friend void class_State(void);

public:
    virtual void update(float) override {}
};

class TestEntity : public Entity
{
    friend void class_Entity(void);
    OBJECT_CAST_CTOR(TestEntity, Entity);

public:
    TestEntity(State& state, vec2 pos)
        : Entity(state, pos) {}
};

void class_State(void) {
    TestState state;

    state.adopt_entity<TestEntity>(glm::vec2 { 0, 0 });

    TEST_CHECK(state.m_entities.size() == 1);

    // NOTIMPL
    // TEST_CHECK(state.get_entity(state.m_entities.begin()->first.guid()) != nullptr);
}

void class_Entity(void) {
    TestState  state;
    TestEntity e(state, { 5.4f, 5.3f });

    TEST_CHECK(e.m_transform.position() == vec2(5.4f, 5.3f));
    e.m_transform.move_by(vec2(1.0f, 1.0f));
    TEST_CHECK(e.m_transform.position() == vec2(6.4f, 6.3f));
    TEST_CHECK(e.m_components.size() == 0);
    TEST_CHECK(e == e.transform().entity());

    class Comp : public Component
    {
    public:
        Comp(Entity& e)
            : Component(e) {}
        virtual void update(float) {}
    };

    e.add_component<Comp>();
    TEST_CHECK(e.m_components.size() == 1);
    TEST_CHECK(e.m_components.at(0)->entity() == e);

    e.m_transform.set_position(vec2(0, 0));
    TEST_CASE("setting transform position");
    TEST_CHECK(e.m_transform.position() == vec2(0, 0));
    e.m_transform.set_rotation(90.0f);
    TEST_CASE("setting transform rotation");
    TEST_CHECK(e.m_transform.rotation() == 90.0f);
}

TEST_LIST = {
    { "sanity checks", sanity_checks },
    { "class GUID", class_GUID },
    { "class ImageFile", class_ImageFile },
    { "class RefPtr basic behaviour", class_RefPtr_basic_behv },
    { "class State", class_State },
    { "class Entity", class_Entity },

    { "class Clock", class_Clock },
    // END
    { nullptr, nullptr }
};

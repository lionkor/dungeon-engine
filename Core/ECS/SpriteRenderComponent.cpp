#include "SpriteRenderComponent.h"
#include "Entity.h"
#include "../State.h"
#include "../Rendering/Renderer.h"

// ATTENTION: spr's position is relative!
SpriteRenderComponent::SpriteRenderComponent(Entity& entity, const Sprite& spr)
    : Component(entity), m_sprite(spr)
{
    Renderer::the().submit(*this);
    // FIXME: push info to renderer lol
}

Sprite& SpriteRenderComponent::sprite()
{
    return m_sprite;
}

const Sprite& SpriteRenderComponent::sprite() const
{
    return m_sprite;
}

void SpriteRenderComponent::set_sprite(const Sprite& spr)
{
    m_sprite = spr;
    Renderer::the().submit(m_sprite);
}

void SpriteRenderComponent::update(float)
{
}

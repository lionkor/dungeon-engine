#include "SpriteRenderComponent.h"
#include "Entity.h"
#include "../State.h"
#include "../Rendering/Renderer.h"

SpriteRenderComponent::SpriteRenderComponent(Entity& entity)
    : Component(entity)
{
    m_entity.state().renderer();
}

Sprite& SpriteRenderComponent::sprite()
{
    ASSERT(m_sprite.material.is_not_null());
    return m_sprite;
}

const Sprite& SpriteRenderComponent::sprite() const
{
    ASSERT(m_sprite.material.is_not_null());
    return m_sprite;
}

void SpriteRenderComponent::set_sprite(const Sprite& spr)
{
    ASSERT(spr.material.is_not_null());
    m_sprite = spr;
}

void SpriteRenderComponent::update(float)
{
    
}

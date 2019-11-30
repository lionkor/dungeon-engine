#ifndef SPRITERENDERCOMPONENT_H
#define SPRITERENDERCOMPONENT_H

#include "../Global.h"
#include "../Rendering/Material.h"
#include "../Rendering/Primitives.h"
#include "../Rendering/Sprite.h"
#include "Component.h"

class SpriteRenderComponent : public Component, public GUID
{
    OBJECT_CAST_CTOR(SpriteRenderComponent, Component, override);
public:
    
    Sprite& sprite();
    const Sprite& sprite() const;
    void set_sprite(const Sprite& spr);

    virtual void update(float) override;
    
protected:
    SpriteRenderComponent(Entity& entity);
    
    Sprite m_sprite;
};

#endif // SPRITERENDERCOMPONENT_H

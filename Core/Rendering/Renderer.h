#ifndef RENDERER_H
#define RENDERER_H

#include "../Global.h"
#include "../Backend.h"
#include "../ECS/SpriteRenderComponent.h"

class Renderer
{
public:
    static Renderer& the();

    virtual void draw();

    virtual GUID submit(const Sprite& spr);
    virtual GUID submit(const SpriteRenderComponent& sprc);

protected:
    Renderer();

    static OwnPtr<Renderer> s_the_renderer;
};

#endif // RENDERER_H

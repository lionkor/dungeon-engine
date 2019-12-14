#include "Renderer.h"
#include "../sfml/SFMLBackend.h"
#include "../Window.h"
#include "../Application.h"

OwnPtr<Renderer> Renderer::s_the_renderer;

void Renderer::draw()
{
    Window::the().backend().clear();
    Window::the().backend().draw();
    Window::the().backend().display();
}

GUID Renderer::submit(const Sprite& spr)
{
    return Window::the().backend().submit(spr);
}

Renderer& Renderer::the()
{
    if (!Renderer::s_the_renderer)
    {
        verbose("Renderer doesn't exist! Creating new Renderer");
        Renderer::s_the_renderer = OwnPtr<Renderer>(new Renderer());
    }
    return *Renderer::s_the_renderer;
}

Renderer::Renderer()
{
}

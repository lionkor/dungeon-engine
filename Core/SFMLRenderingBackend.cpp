#include "SFMLRenderingBackend.h"

SFMLRenderingBackend::SFMLRenderingBackend()
    : m_window(OwnPtr<sf::RenderWindow>::make(sf::VideoMode(800, 600), "Window"))
{
}

void SFMLRenderingBackend::clear()
{
    m_window->clear();
}

void SFMLRenderingBackend::draw_everything()
{
    NOTIMPL
}

void SFMLRenderingBackend::display()
{
    m_window->display();
}

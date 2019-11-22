#ifndef SFMLRENDERINGBACKEND_H
#define SFMLRENDERINGBACKEND_H

#include "Global.h"
#include "RenderingBackend.h"

class SFMLRenderingBackend : public RenderingBackend
{
public:
    SFMLRenderingBackend();
    
    void clear();
    void draw_everything();
    void display();
    
protected:
    OwnPtr<sf::RenderWindow> m_window;
};

#endif // SFMLRENDERINGBACKEND_H

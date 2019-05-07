#include "Bomba.h"

Bomba::Bomba(float xPos, float yPos)
{
    bomba.setTexture(mundo::getMundo()->bombaTex);
    bomba.setScale(0.15f,0.15f);
    bomba.setOrigin(sf::Vector2f(bomba.getLocalBounds().width/2,bomba.getLocalBounds().height/2));
    bomba.setPosition(xPos,yPos);
}
bool Bomba::explosion(){

}
void Bomba::render(sf::RenderWindow &Window){
    Window.draw(bomba);
}
Bomba::~Bomba()
{
    //dtor
}

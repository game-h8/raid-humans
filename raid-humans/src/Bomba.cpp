#include "Bomba.h"

Bomba::Bomba(float xPos, float yPos)
{
    bomba.setTexture(mundo::getMundo()->bombaTex);
    bomba.setScale(0.15f,0.15f);
    bomba.setOrigin(sf::Vector2f(bomba.getLocalBounds().width/2,bomba.getLocalBounds().height/2));
    bomba.setPosition(xPos,yPos);
    viva=true;
}
bool Bomba::explosion(){

}
bool Bomba::colision(int i){
bool colisiona=false;
    if(bomba.getGlobalBounds().intersects(mundo::getMundo()->enemigosFuera->at(i).hitbox.getGlobalBounds())){
        viva=false;
        colisiona=true;
        mundo::getMundo()->enemigosFuera->at(i).playerHit(1000);
        mundo::getMundo()->enemigosFuera->erase(mundo::getMundo()->enemigosFuera->begin()+i);
    }

return colisiona;
}
void Bomba::render(sf::RenderWindow &Window){
    if(viva)
        Window.draw(bomba);
}
Bomba::~Bomba()
{
    //dtor
}

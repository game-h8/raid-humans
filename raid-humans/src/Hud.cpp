#include "Hud.h"

Hud::Hud()
{
   // nvida = mundo::getMundo()->jugador->salud;

    cajavida.setSize(Vector2f(300,40));
    cajavida.setFillColor(Color(50,205,50,255));
    cajavida.setPosition(Vector2f(50,80));

}

void Hud::draw(sf::RenderWindow &Window){
    Window.draw(cajavida);
}
void Hud::updateHud(){
    int health = mundo::getMundo()->jugador->salud;
    cajavida.setSize(Vector2f((health*300)/500,40));
}
Hud::~Hud()
{
    //dtor
}


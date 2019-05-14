#include "Hud.h"

Hud::Hud()
{
   // nvida = mundo::getMundo()->jugador->salud;
    corazon.setTexture(mundo::getMundo()->corazontext);
    corazon.setPosition(55,76);
    corazon.setScale(0.1f,0.1f);

    monedilla.setTexture(mundo::getMundo()->monedatext);
    monedilla.setPosition(645,35.0f);
    monedilla.setScale(0.41f,0.4f);

    cajavida.setSize(Vector2f(240,20));
    cajavida.setFillColor(Color(255,0,0,255));
    cajavida.setPosition(Vector2f(74,82.5f));

    cajavidabackground.setSize(Vector2f(245,30));
    cajavidabackground.setFillColor(Color(0,0,0,255));
    cajavidabackground.setPosition(Vector2f(74,77.5f));

}

void Hud::draw(sf::RenderWindow &Window){

    Window.draw(cajavidabackground);
    Window.draw(cajavida);
    Window.draw(corazon);
    Window.draw(monedilla);
}
void Hud::updateHud(){
    int health = mundo::getMundo()->jugador->salud;
    cajavida.setSize(Vector2f((health*240)/500,20));
}
Hud::~Hud()
{
    //dtor
}


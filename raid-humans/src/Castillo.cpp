#include "Castillo.h"

Castillo::Castillo()
{
    castilloSprite.setTexture(mundo::getMundo()->castilloTex);

    castilloSprite.setScale(0.7f,0.7f);
    castilloSprite.setOrigin(sf::Vector2f(600/2,500/2));
    //castilloSprite.setRotation(90);
    castilloSprite.setPosition(650,350);
    vida=2000;

    hitbox.setSize(Vector2f(220,220));
    hitbox.setFillColor(Color(255,0,0,155));
    //hitbox.setOrigin(8,-5);
    hitbox.setPosition(Vector2f(540,250));
}

void Castillo::draw(sf::RenderWindow &Window){
    Window.draw(castilloSprite);
    if(mundo::getMundo()->getDebug()){
        Window.draw(hitbox);
    }
}

Castillo::~Castillo()
{
    //dtor
}

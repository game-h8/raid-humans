#include "../include/Bala.h"
#include <iostream>

Bala::Bala(float posX, float posY)
{
    if(!balaTex.loadFromFile("bala.png")){
        std::cerr <<"Error al cargar la imagen de bala";
        exit(0);
    }
    balaSprite.setTexture(balaTex);
    balaSprite.scale(0.02,0.02);
    balaSprite.setOrigin(sf::Vector2f(5.5,5.5));
    nextPosX = posX;
    nextPosY= posY;


    viva=true;
}

void Bala::disparar(){
float speed=1.5;

    float angle = atan2(nextPosY - balaSprite.getPosition().y, nextPosX - balaSprite.getPosition().x);
    angle = angle * 180 / (atan(1) * 4);
    sf::Vector2f newpos((cos(angle))*2, (sin(angle))*2);

    direccion = newpos;

    balaSprite.move(direccion);

    /*float sX = balaSprite.getPosition().x - torreta.getPosX();
    float sY = balaSprite.getPosition().y - torreta.getPosY();

    if (sX > 320 || sX < -320 || sY > 240 || sY < -240 )
    {
        viva = false;
    }
*/
}

void Bala::setPos(sf::Vector2f newPos){
    balaSprite.setPosition(newPos);
}
int Bala::getX(){
    return balaSprite.getPosition().x;
}
int Bala::getY(){
    return balaSprite.getPosition().y;
}
sf::FloatRect Bala::getGlobal(){
    return balaSprite.getGlobalBounds();
}
void Bala::draw(sf::RenderWindow &Window){
    //if(viva)
        Window.draw(balaSprite);
}

Bala::~Bala()
{
    //dtor
}

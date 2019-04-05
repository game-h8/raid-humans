#include "../include/Bala.h"
#include <iostream>
#include <math.h>

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

void Bala::disparar(float time){

    float speed=200;

    sf::Vector2f newpos((cos(angle))*2, (sin(angle))*2);
    direccion = newpos;

    xlast = x;
    ylast = y;
    //Avanzar a la siguiente posicion
    x=x+direccion.x*speed*time;
    y=y+direccion.y*speed*time;


/*
    float sX = x - torreta.getPosX();
    float sY = y - torreta.getPosY();

    if (sX > 320 || sX < -320 || sY > 240 || sY < -240 )
    {
        viva = false;
    }
*/
}

float Bala::setPos(sf::Vector2f newPos){
    balaSprite.setPosition(newPos);
    x=newPos.x;
    y=newPos.y;
    xlast=newPos.x;
    ylast=newPos.y;
    //Calcular angulo hacia el que ira la bala
    angle = atan2(nextPosY - y, nextPosX - x);
    balaSprite.setRotation(angle*180/M_PI +90);//Direccion de la bala
    return angle;
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
void Bala::render(float ticks, sf::RenderWindow &Window){
    //if(viva)
    balaSprite.setPosition(xlast*(1-ticks) + x*ticks,ylast*(1-ticks)+y*ticks);
        Window.draw(balaSprite);
}

Bala::~Bala()
{
    //delete balaSprite;
}

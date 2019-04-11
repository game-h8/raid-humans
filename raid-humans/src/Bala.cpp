#include "../include/Bala.h"
#include <iostream>
#include <math.h>

Bala::Bala(float posX, float posY)
{

    balaSprite.setTexture(mundo::getMundo()->balaTex);
    balaSprite.scale(0.02,0.02);
    balaSprite.setOrigin(sf::Vector2f(5.5,5.5));
    nextPosX = posX;
    nextPosY= posY;
cout<<"Creo una bala. " <<endl;
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


    if(x<0 || y < 0 || x>800 || y>600){
        viva = false;
    }

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
void Bala::colision(enemigos enemigo){
    if(balaSprite.getGlobalBounds().intersects(enemigo.getGlobal())){
        viva=false;
    }
}
void Bala::render(float ticks, sf::RenderWindow &Window){
    balaSprite.setPosition(xlast*(1-ticks) + x*ticks,ylast*(1-ticks)+y*ticks);
    if(viva){
        Window.draw(balaSprite);
    }
}

Bala::~Bala()
{
    //delete balaSprite;
}

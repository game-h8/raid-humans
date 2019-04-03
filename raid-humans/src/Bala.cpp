#include "../include/Bala.h"

Bala::Bala(char dir)
{
    bala.setSize(sf::Vector2f(5.f,5.f));
    sf::Color color(255, 255, 0);
    bala.setFillColor(color);
    direccion = dir;
    viva=true;
}
/*
void Bala::disparar(float speed, Torreta torreta){

    switch(direccion) {
        case 'r':
            bala.move(speed, 0);
        break;
        case 'l':
            bala.move(-speed, 0);
        break;
        case 'd':
            bala.move(0, speed);
        break;
        case 'u':
            bala.move(0, -speed);
        break;
    }

    float sX = bala.getPosition().x - torreta.getPosX();
    float sY = bala.getPosition().y - torreta.getPosY();

    if (sX > 320 || sX < -320 || sY > 240 || sY < -240 )
    {
        viva = false;
    }

}
*/
void Bala::setPos(sf::Vector2f newPos){
    bala.setPosition(newPos);
}
int Bala::getLeft(){
    return bala.getPosition().x;
}
int Bala::getTop(){
    return bala.getPosition().y;
}
int Bala::getBottom(){
    return bala.getPosition().y + bala.getSize().y;
}
int Bala::getRight(){
    return bala.getPosition().x + bala.getSize().x;
}
sf::FloatRect Bala::getGlobal(){
    return bala.getGlobalBounds();
}
void Bala::draw(sf::RenderWindow &Window){
    if(viva)
        Window.draw(bala);
}

Bala::~Bala()
{
    //dtor
}

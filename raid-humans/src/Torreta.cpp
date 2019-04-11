#include "../include/Torreta.h"

Torreta::Torreta()
{

    torretaSprite.setTexture(mundo::getMundo()->torretaTex);
    torretaSprite.setTextureRect(IntRect(16,5,96,118));
    torretaSprite.setScale(0.5f,0.5f);

    torretaSprite.setOrigin(sf::Vector2f(15.4,15.4));
}
int Torreta::getX(){
    return torretaSprite.getPosition().x;
}
int Torreta::getY(){
    return torretaSprite.getPosition().y;
}
void Torreta::draw(sf::RenderWindow &Window){
    Window.draw(torretaSprite);
}

void Torreta::dibujarSprite(){
    if(timeTorreta.getElapsedTime().asMilliseconds() < 200){
       torretaSprite.setTextureRect(IntRect(143,5,96,118));
    }
    else if(timeTorreta.getElapsedTime().asMilliseconds() < 400){
        torretaSprite.setTextureRect(IntRect(16,5,96,118));
    }
    else{
        timeTorreta.restart();
    }
}

void Torreta::setPos(sf::Vector2f newPos){
    torretaSprite.setPosition(newPos);
}
void Torreta::rotarTorreta(float angle){
    torretaSprite.setRotation(angle*180/M_PI +90);

}
Torreta::~Torreta()
{
/*
Revisar Delete

*/


}
sf::Sprite Torreta::getSprite() {
    return torretaSprite;
}

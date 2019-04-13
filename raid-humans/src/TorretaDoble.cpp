#include "TorretaDoble.h"

TorretaDoble::TorretaDoble()
{
    torretaSprite.setTexture(mundo::getMundo()->torretaTex);
    torretaSprite.setTextureRect(IntRect(16,5,96,118));
    torretaSprite.setScale(0.4f,0.4f);
    torretaSprite.setOrigin(sf::Vector2f(96/2,118/2));
}

TorretaDoble::~TorretaDoble()
{
    //dtor
}

void TorretaDoble::draw(sf::RenderWindow &Window){
    Window.draw(torretaSprite);
}

void TorretaDoble::dibujarSprite(){
    if(timeTorreta.getElapsedTime().asMilliseconds() < 200){
       torretaSprite.setTextureRect(IntRect(143,5,96,118));
    }
    else if(timeTorreta.getElapsedTime().asMilliseconds() < 400){
        torretaSprite.setTextureRect(IntRect(16,5,96,118));
    }

}

void TorretaDoble::setPos(sf::Vector2f newPos){
    torretaSprite.setPosition(newPos.x,newPos.y);
}
void TorretaDoble::rotarTorreta(float angle){
    torretaSprite.setRotation(angle*180/M_PI +90);

}
TorretaDoble::~Torreta()
{
/*
Revisar Delete

*/


}
sf::Sprite TorretaDoble::getSprite() {
    return torretaSprite;
}

#include "../include/Torreta.h"

Torreta::Torreta(std::string imgDirectory)
{
    if(!torretaTex.loadFromFile(imgDirectory)){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
    torretaSprite.setTexture(torretaTex);
    torretaSprite.setScale(0.06f,0.06f);
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

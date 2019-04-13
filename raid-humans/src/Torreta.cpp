#include "../include/Torreta.h"

Torreta::Torreta()
{

    torretaSprite.setTexture(mundo::getMundo()->torretaTex);
    torretaSprite.setTextureRect(IntRect(16,5,96,118));
    torretaSprite.setScale(0.4f,0.4f);
    torretaSprite.setOrigin(sf::Vector2f(96/2,118/2));
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

}

void Torreta::setPos(sf::Vector2f newPos){
    torretaSprite.setPosition(newPos.x,newPos.y);
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
bool Torreta:: enemigohit(float dano){

bool muerto=false;


    if(vida-dano<=0) {
       // muere();

       muerto=true;

    }
    else{
        vida=vida-dano;

    timedanoTorreta.restart();

       torretaSprite.setColor(Color(255,0,0,155));
        }

    return muerto;


}
void Torreta:: danoenemigo(){

     if(timedanoTorreta.getElapsedTime().asMilliseconds()>=200){

             torretaSprite.setColor(Color(255,255,255,255));

        }


}

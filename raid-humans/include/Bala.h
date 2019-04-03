#ifndef BALA_H
#define BALA_H
#include <SFML/Graphics.hpp>
#include "player.h"
#include <math.h>

class Torreta;
class player;
class Bala
{
    public:
        sf::Vector2f direccion;
        bool viva;
        float nextPosX;
        float nextPosY;
        Bala(float posX, float posY);
        void disparar();
        void setPos(sf::Vector2f newPos);
        int getY();
        int getX();
        sf::FloatRect getGlobal();
        void draw(sf::RenderWindow &Window);
        virtual ~Bala();
    private:
        sf::Texture balaTex;
        sf::Sprite balaSprite;
};

#endif // BALA_H

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
        float x;
        float y;
        float xlast;
        float ylast;
        float angle;
        Bala(float posX, float posY);
        void disparar(float time);
        void setPos(sf::Vector2f newPos);
        int getY();
        int getX();
        sf::FloatRect getGlobal();
        void render(float ticks, sf::RenderWindow &Window);
        virtual ~Bala();
    private:
        sf::Texture balaTex;
        sf::Sprite balaSprite;
};

#endif // BALA_H

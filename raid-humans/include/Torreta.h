#ifndef TORRETA_H
#define TORRETA_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <mundo.h>

class Torreta
{
    public:
        Torreta();
        int getX();
        int getY();
        void setPos(sf::Vector2f newPos);
        void rotarTorreta(float angle);
        void draw(sf::RenderWindow &Window);
        void dibujarSprite();
        sf::Sprite getSprite();
        ~Torreta();
    private:

        sf::Sprite torretaSprite;
        Clock timeTorreta;
};

#endif // TORRETA_H

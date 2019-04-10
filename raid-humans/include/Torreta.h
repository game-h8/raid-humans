#ifndef TORRETA_H
#define TORRETA_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Torreta
{
    public:
        Torreta(std::string imgDirectory);
        int getX();
        int getY();
        void setPos(sf::Vector2f newPos);
        void rotarTorreta(float angle);
        void draw(sf::RenderWindow &Window);
        sf::Sprite getSprite();
        ~Torreta();
    private:
        sf::Texture torretaTex;
        sf::Sprite torretaSprite;
};

#endif // TORRETA_H

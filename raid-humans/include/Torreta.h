#ifndef TORRETA_H
#define TORRETA_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Torreta
{
    public:
        Torreta(std::string imgDirectory);
        int getX();
        int getY();
        void setPos(sf::Vector2f newPos);
        void draw(sf::RenderWindow &Window);
        ~Torreta();
    private:
        sf::Texture torretaTex;
        sf::Sprite torretaSprite;
};

#endif // TORRETA_H

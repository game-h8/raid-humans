#ifndef TORRETADOBLE_H
#define TORRETADOBLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <mundo.h>

class TorretaDoble
{
    public:
        TorretaDoble();
        float x;
        float y;
        void setPos(sf::Vector2f newPos);
        void rotarTorreta(float angle);
        void draw(sf::RenderWindow &Window);
        void dibujarSprite();
        sf::Sprite getSprite();
        sf::Clock timeTorreta;
        ~Torreta();
        sf::Sprite torretaSprite;

        virtual ~TorretaDoble();

    protected:

    private:
};

#endif // TORRETADOBLE_H

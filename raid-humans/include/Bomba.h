#ifndef BOMBA_H
#define BOMBA_H
#include <SFML/Graphics.hpp>
#include <mundo.h>
#include <enemigos.h>

class Bomba
{
    public:
        Bomba(float xPos, float yPos);
        bool explosion();
        bool viva;
        bool colision(int i);
        void render(sf::RenderWindow &Window);
        sf::Sprite bomba;
        virtual ~Bomba();

    protected:

    private:
};

#endif // BOMBA_H

#ifndef BOMBA_H
#define BOMBA_H
#include <SFML/Graphics.hpp>
#include <mundo.h>

class Bomba
{
    public:
        Bomba(float xPos, float yPos);
        bool explosion();
        void render(sf::RenderWindow &Window);
        sf::Sprite bomba;
        virtual ~Bomba();

    protected:

    private:
};

#endif // BOMBA_H

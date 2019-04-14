#ifndef CASTILLO_H
#define CASTILLO_H
#include <SFML/Graphics.hpp>
#include <mundo.h>

class Castillo
{
    public:
        Castillo();
        int vida;
        void draw(sf::RenderWindow &Window);
        virtual ~Castillo();
        sf::Sprite castilloSprite;
        sf::RectangleShape hitbox;

    protected:

    private:
};

#endif // CASTILLO_H

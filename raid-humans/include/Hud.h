#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
#include "mundo.h"
#include "player.h"

class Hud
{
    public:
        Hud();
        int nvida;
        void draw(sf::RenderWindow &Window);
        virtual ~Hud();
        sf::Sprite corazon;
        sf::RectangleShape cajavida;
        sf::RectangleShape cajavidabackground;
        void updateHud();
    protected:

    private:
};

#endif // HUD_H

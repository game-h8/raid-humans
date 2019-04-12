#ifndef MONEDA_H
#define MONEDA_H
#include <SFML/Graphics.hpp>
#include <mundo.h>
#include <math.h>

class Moneda
{
    public:
        Moneda(float x, float y, int valor);
        int valor;
        bool movimiento(float xJugador, float yJugador);
        void render(sf::RenderWindow &Window);
        sf::RectangleShape hitbox;
        sf::Sprite mSprite;
        virtual ~Moneda();
    protected:

    private:


};

#endif // MONEDA_H

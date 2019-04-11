#ifndef MONEDA_H
#define MONEDA_H
#include <SFML/Graphics.hpp>


class Moneda
{
    public:
        Moneda(float x, float y, int valor);
        virtual ~Moneda();
        int valor;
        int getX();
        int getY();
        void movimiento(float x, float y);
        void render(sf::RenderWindow &Window);
        sf::RectangleShape hitbox;
        sf::Sprite mSprite;
        sf::Texture mTex;
    protected:

    private:


};

#endif // MONEDA_H

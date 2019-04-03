#ifndef BALA_H
#define BALA_H
#include <SFML/Graphics.hpp>

class Torreta;
class Bala
{
    public:
        char direccion;
        bool viva;
        Bala(char dir);
        void disparar(float speed, Torreta torreta);
        void setPos(sf::Vector2f newPos);
        int getLeft();
        int getTop();
        int getBottom();
        int getRight();
        sf::FloatRect getGlobal();
        void draw(sf::RenderWindow &Window);
        virtual ~Bala();
    private:
        sf::RectangleShape bala;
};

#endif // BALA_H

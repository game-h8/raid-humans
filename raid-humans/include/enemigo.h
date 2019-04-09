#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include <player.h>

using namespace sf;
using namespace std;

class enemigo {

public:
        enemigo(); //defecto
        enemigo(float x, float y); //parametros
        enemigo(const enemigo& E); //copia
        ~enemigo(); //destructor

        RectangleShape hitbox;
        Texture   eTexture;
        Sprite    eSprite;
        float     x;
        float     y;
        float     xlast;
        float     ylast;
        Vector2f   vel;
        Vector2f objetivo;
        float saludEnemigo;
        float danioEnemigo;
        float velocidad = 10;
        bool ataca=false;

        Vector2f moveEnemy(float time);
        void render(float ticks, RenderWindow& ventana);
        bool ataque(player * p);
        void setObjetivo(Vector2f obj);

protected:
private:



};

#endif // ENEMIGOS_H

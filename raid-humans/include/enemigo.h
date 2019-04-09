#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <iostream>
#include<SFML/Graphics.hpp>

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
        float saludEnemigo;
        float danioEnemigo;

        Vector2f moveEnemy(Vector2f a, float time);
        void render(float ticks, RenderWindow& ventana);

protected:
private:



};


#endif // ENEMIGO_H

#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class enemigos {

public:
        enemigos(); //defecto
        enemigos(float x, float y); //parametros
        enemigos(const enemigos& E); //copia
        ~enemigos(); //destructor

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

        Vector2f moveEnemy(float time);
        void render(float ticks, RenderWindow& ventana);
        void setObjetivo(Vector2f obj);

protected:
private:



};

#endif // ENEMIGOS_H

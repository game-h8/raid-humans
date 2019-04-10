#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include <player.h>
#include <Torreta.h>

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
        float velocidad = 50;
        bool ataca=false;
        bool atacaTorre=false;


        sf::FloatRect getGlobal();
        void moveEnemy(float time, vector<enemigos>, vector<Torreta>, int a);
        void render(float ticks, RenderWindow& ventana);
        void colisionEnemigos(Vector2f ene);
        bool ataque(player * p);
        void setObjetivo(Vector2f obj);
        void atacaTorretaCercana(vector<Torreta> vecTor);
        void atacaJugador(player &jugador);

protected:
private:



};

#endif // ENEMIGOS_H

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include<SFML/Graphics.hpp>
<<<<<<< HEAD
#include <SFML/System/Clock.hpp>


#define kVel 100
=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)

using namespace sf;
using namespace std;



class player
{
    public:

        player();
        player(string imgDirectory, float x, float y);
        virtual ~player();

        RectangleShape hitbox;
<<<<<<< HEAD
        RectangleShape hitboxArma;

=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)
        Texture   pTexture;
        Sprite    pSprite;
        float     x;
        float     y;
        float     xlast;
        float     ylast;
        Vector2f   vel;
<<<<<<< HEAD
        int        estado;    //0-> reposo ,1-> movimiento, 2-> ataque (para renderizar)
=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)





    Vector2f movePlayer(Vector2f a, float time);
<<<<<<< HEAD

    void render(float ticks, RenderWindow& ventana);
    void calcularVelocidadPlayer(vector<int> inputs,float time);
    void toggleDebug();
=======
    void render(float ticks, RenderWindow& ventana);

>>>>>>> Enemigo(ataque,movimiento,yGenerar)

    protected:
    private:

<<<<<<< HEAD
    Clock timejugador;
    bool debug = false;
=======

>>>>>>> Enemigo(ataque,movimiento,yGenerar)


};



#endif // PLAYER_H


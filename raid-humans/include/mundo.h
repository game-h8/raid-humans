#ifndef MUNDO_H
#define MUNDO_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include <Mapa.h>

using namespace sf;
class player;
class Mapa;

class mundo
{
    public:
        mundo();
        virtual ~mundo();

        static mundo* getMundo(); //Singleton

        void toggleDebug();
        bool getDebug();
        void test();

        Mapa *mapa;
        RenderWindow * ventana;
        player * jugador;


        sf::Texture torretaTex;
        sf::Texture   eTexture;
        sf::Texture balaTex;


    protected:

    private:
        static mundo* _instancia;
        bool debug = false;

};

#endif // MUNDO_H

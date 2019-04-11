#ifndef MUNDO_H
#define MUNDO_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include <Mapa.h>
#include <enemigos.h>
#include <vector>
#include <Torreta.h>
#include <Bala.h>
#include <Moneda.h>

using namespace sf;
class enemigos;
class player;
class Mapa;
class Moneda;
class Bala;


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

        vector<enemigos> * enemigosFuera; //vector de enemigos que se encuentran en pantalla
        vector<enemigos> * enemigosEspera;
        vector<Torreta> * vectorTorreta;
        vector<Bala> * vectorBalas;
        vector<Moneda> * vectorMonedas;



    protected:

    private:
        static mundo* _instancia;
        bool debug = false;

};

#endif // MUNDO_H

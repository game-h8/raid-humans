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
#include <BalaMisil.h>
#include <Castillo.h>

using namespace sf;
class enemigos;
class player;
class Mapa;
class Moneda;
class Bala;
class BalaMisil;
class Castillo;

class mundo
{
    public:
        mundo();
        virtual ~mundo();

        static mundo* getMundo(); //Singleton

        void toggleDebug();
        bool getDebug();
        void test();
        void cambiarTipoTorreta(int tipo);
        int getCoins();
        bool gastaCoins(int coins);
        void addCoins(int coins);
        Mapa *mapa;
        RenderWindow * ventana;
        Castillo *castillo;
        player * jugador;



        sf::Texture torretaTex;
        sf::Texture castilloTex;
        sf::Texture   eTexture;
        sf::Texture balaTex;
        sf::Texture coinTex;
        sf::Texture splasTexture;
        sf::Texture splasmenu;
        sf::Texture botoninicio;
        sf::Texture compratorreta1;
        sf::Texture compratorreta2;
        sf::Texture compramejora;
        sf::Texture botoncambioestado;
        sf::Texture compratorreta1no;
        sf::Texture compratorreta2no;
        sf::Texture compramejorano;
        sf::Texture corazontext;

        sf::Text dinero;
        sf::Font font;
        int tipoTorreta;
        int monedas;

        vector<enemigos> * enemigosFuera; //vector de enemigos que se encuentran en pantalla
        vector<enemigos> * enemigosEspera;
        vector<Torreta> * vectorTorreta;
        vector<Bala> * vectorBalas;
        vector<BalaMisil> * vectorBalasMisil;
        vector<Moneda> * vectorMonedas;



    protected:

    private:
        static mundo* _instancia;
        bool debug = false;

};

#endif // MUNDO_H

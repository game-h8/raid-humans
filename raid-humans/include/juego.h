#ifndef JUEGO_H
#define JUEGO_H


#include <SFML/System/Clock.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "player.h"
#include "Bala.h"
#include "Torreta.h"
#include "enemigos.h"
#include "Moneda.h"
#include <vector>
#include <Mapa.h>
#include <StateMachine.h>
#include <BalaMisil.h>
#include <sstream>

using namespace sf;


class juego
{
    public:
        juego(Vector2u resolucion);
        void inicializar();      //inicializar las variables del juego
        void update(float elapsedTime);
         void colisionEE();
        void renderizar(float percentick);
        vector<int> getInputs();
        Vector2f calcularVelocidadPlayer(vector<int> inputs);
        void dibujarSelector();
        void addTorreta();
        void disparar();
        void recogerMoneda();
        vector<Torreta> getTorretas();
        bool IsSpriteCLicker(sf::Sprite es);



    protected:

    private:
        Mapa *mapa;
        RenderWindow * ventana;
        player * jugador;
        StateMachine * estado;
        vector<Torreta> vectorTorreta;
        vector<Bala> vectorBalas;
        vector<Moneda> vectorMonedas;
        vector<enemigos> enemigosFuera; //vector de enemigos que se encuentran en pantalla
        vector<enemigos>enemigosEspera; //vector de enemigos para hacer spawn*/
        vector<BalaMisil> vectorBalasMisil;
        Sprite dSprite;
        Texture dTexture;


        Clock clock;
        Clock updateCLock;
        Time tiempo = clock.getElapsedTime();


        //variables de tiempo para el spawn
        Clock clockSpawn;
        Time tiempoSpawn =  seconds(3.f);

        //variables de tiempo para la bala
        Clock clockBala;
        Time tiempoBala = clock.getElapsedTime();

        //variables de tiempo para el ataque
        Clock clockAttack;
        Time tiempoAttack = seconds(1.f);


        sf::Sprite portada;
        sf::Sprite menu;
        sf::Sprite boton;
        sf::Sprite torretaCompra1;
        sf::Sprite torretaCompra2;
        sf::Sprite espadaCompra;

        sf::Sprite continuarRonda;

        sf::Sprite torretaFantasma; //la que te sigue al comprar
};
#endif // JUEGO_H


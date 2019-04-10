#ifndef JUEGO_H
#define JUEGO_H


#include <SFML/System/Clock.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "Bala.h"
#include "Torreta.h"
#include "enemigos.h"
#include <vector>
#include <Mapa.h>

using namespace sf;


class juego
{
    public:
        juego(Vector2u resolucion);
        void inicializar();      //inicializar las variables del juego
        void update(float elapsedTime);
        void renderizar(float percentick);
        vector<int> getInputs();
        Vector2f calcularVelocidadPlayer(vector<int> inputs);
        void dibujarSelector();
        void addTorreta();
        void disparar();


    protected:

    private:
        Mapa *mapa;
        RenderWindow * ventana;
        player * jugador;
        vector<Torreta> vectorTorreta;
        vector<Bala> vectorBalas;
        vector<enemigos> enemigosFuera; //vector de enemigos que se encuentran en pantalla
        vector<enemigos>enemigosEspera; //vector de enemigos para hacer spawn*/
};

#endif // JUEGO_H


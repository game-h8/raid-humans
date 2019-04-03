#ifndef JUEGO_H
#define JUEGO_H


#include <SFML/System/Clock.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "Bala.h"
#include "Torreta.h"
#include <vector>

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
        RenderWindow * ventana;
        player * jugador;
        std::vector<Torreta> vectorTorreta;
        std::vector<Bala> vectorBalas;
};

#endif // JUEGO_H


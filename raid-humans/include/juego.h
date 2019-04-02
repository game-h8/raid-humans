#ifndef JUEGO_H
#define JUEGO_H


#include <SFML/System/Clock.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <player.h>

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


    protected:

    private:
        RenderWindow * ventana;
        player * jugador;
};

#endif // JUEGO_H


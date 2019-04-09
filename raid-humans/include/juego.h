#ifndef JUEGO_H
#define JUEGO_H


#include <SFML/System/Clock.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <player.h>
#include <enemigo.h>

using namespace sf;
using namespace std;


class juego
{
    public:
        juego(Vector2u resolucion);
        void inicializar();      //inicializar las variables del juego
        void update(float elapsedTime);
        void renderizar(float percentick);
        vector<int> getInputs();
        Vector2f calcularVelocidadPlayer(vector<int> inputs);
        /*void recargarSpawn();
        void meterEnemigosEspera();*/


    protected:

    private:
        RenderWindow * ventana;
        player * jugador;
        vector<enemigo> enemigosFuera; //vector de enemigos que se encuentran en pantalla
        vector<enemigo>enemigosEspera; //vector de enemigos para hacer spawn
        Sprite dSprite;
        Texture dTexture;

};

#endif // JUEGO_H


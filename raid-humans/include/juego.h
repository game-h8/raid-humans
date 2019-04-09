#ifndef JUEGO_H
#define JUEGO_H


#include <SFML/System/Clock.hpp>
#include <iostream>
<<<<<<< HEAD
#include <SFML/Graphics.hpp>
#include "player.h"
#include "Bala.h"
#include "Torreta.h"
#include "enemigos.h"
#include <vector>

using namespace sf;
=======
#include <vector>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <player.h>
#include <enemigo.h>

using namespace sf;
using namespace std;
>>>>>>> Enemigo(ataque,movimiento,yGenerar)


class juego
{
    public:
        juego(Vector2u resolucion);
        void inicializar();      //inicializar las variables del juego
        void update(float elapsedTime);
        void renderizar(float percentick);
        vector<int> getInputs();
        Vector2f calcularVelocidadPlayer(vector<int> inputs);
<<<<<<< HEAD
        void dibujarSelector();
        void addTorreta();
        void disparar();
=======
        /*void recargarSpawn();
        void meterEnemigosEspera();*/

>>>>>>> Enemigo(ataque,movimiento,yGenerar)

    protected:

    private:
        RenderWindow * ventana;
        player * jugador;
<<<<<<< HEAD
        vector<Torreta> vectorTorreta;
        vector<Bala> vectorBalas;
        vector<enemigos> enemigosFuera; //vector de enemigos que se encuentran en pantalla
        vector<enemigos>enemigosEspera; //vector de enemigos para hacer spawn*/
=======
        vector<enemigo> enemigosFuera; //vector de enemigos que se encuentran en pantalla
        vector<enemigo>enemigosEspera; //vector de enemigos para hacer spawn*/
        Sprite dSprite;
        Texture dTexture;

>>>>>>> Enemigo(ataque,movimiento,yGenerar)
};

#endif // JUEGO_H


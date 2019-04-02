#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
using namespace sf;


class juego
{
    public:
        juego(Vector2u resolucion);
        void inicializar();      //inicializar las variables del juego
        void update();
        void renderizar();


    protected:

    private:
        RenderWindow* ventana;
};

#endif // JUEGO_H

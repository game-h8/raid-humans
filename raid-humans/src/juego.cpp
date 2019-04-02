#include "juego.h"

juego::juego(Vector2u resolucion)
{
    //ctor
inicializar();
 ventana = new RenderWindow (VideoMode(resolucion.x, resolucion.y), "Raid humans");

}

juego::~juego()
{
    //dtor


}


juego::void inicializar() { //inicializar las variables del juego



}


juego::void update(){


}


juego::void renderizar(){


}

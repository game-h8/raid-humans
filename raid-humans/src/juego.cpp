#include "juego.h"

juego::juego(Vector2u resolucion)
{
    //ctor
inicializar();
 ventana = new RenderWindow (VideoMode(resolucion.x, resolucion.y), "Raid humans");
 while(ventana->isOpen()){
    update();
    renderizar();
 }

}
/*
juego::~juego()
{
    //dtor


}
*/

void juego:: inicializar() { //inicializar las variables del juego


}


void juego:: update(){


}


void juego:: renderizar(){
    ventana->display();

}

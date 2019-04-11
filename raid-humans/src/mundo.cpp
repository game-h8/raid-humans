#include "mundo.h"
using namespace std;
mundo::mundo()
{

    if(!torretaTex.loadFromFile("ballesta.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }


    if (!eTexture.loadFromFile("resources/enemigo.png"))
    {
        std::cerr << "Error cargando la imagen del enemigo resources/sprites.png" << std::endl;
        exit(0);
    }

    if(!balaTex.loadFromFile("bala.png")){
        std::cerr <<"Error al cargar la imagen de bala";
        exit(0);
    }



}

mundo * mundo::_instancia=NULL;

mundo * mundo::getMundo(){

    if(_instancia==NULL){
        _instancia = new mundo();
    }
    return _instancia;

}

void mundo::toggleDebug(){

if(debug) debug=false;
else debug = true;

}

bool mundo::getDebug(){

return debug;
}

mundo::~mundo()
{
    //dtor
}
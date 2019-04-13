#include "mundo.h"
using namespace std;
mundo::mundo()
{

    if(!torretaTex.loadFromFile("resources/TyB.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }


    if (!eTexture.loadFromFile("resources/enemigo.png"))
    {
        std::cerr << "Error cargando la imagen del enemigo resources/sprites.png" << std::endl;
        exit(0);
    }

    if(!balaTex.loadFromFile("resources/TyB.png")){
        std::cerr <<"Error al cargar la imagen de bala";
        exit(0);
    }

    if(!coinTex.loadFromFile("resources/CoinSheet.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }

tipoTorreta=1;


}

mundo * mundo::_instancia=NULL;

void mundo::cambiarTipoTorreta(){
    if(tipoTorreta==1){
            tipoTorreta=2;
            cout <<"Tipo de torreta: "<<tipoTorreta<<endl;
    }
    else{
        tipoTorreta=1;
    }
}

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

void mundo::test(){

cout << enemigosEspera->size() << endl;
}

#include "mundo.h"
using namespace std;
mundo::mundo()
{

    if(!corazontext.loadFromFile("resources/heart.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
     if(!torretaTex.loadFromFile("resources/TyB.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }

    if(!castilloTex.loadFromFile("resources/Castillo.png")){
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

    if(!splasTexture.loadFromFile("resources/Splash Background.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }


    if(!splasmenu.loadFromFile("resources/sky.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }

     if(!botoninicio.loadFromFile("resources/PlayButton.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }



     if(!compratorreta1.loadFromFile("resources/MejorTorreta1.jpg")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
     if(!compratorreta2.loadFromFile("resources/MejorTorreta2.jpg")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
     if(!compramejora.loadFromFile("resources/MejorEspada.jpg")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
     if(!botoncambioestado.loadFromFile("resources/Play.jpg")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
       if(!compratorreta1no.loadFromFile("resources/MejorTorreta1Bloqueda.jpg")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
     if(!compratorreta2no.loadFromFile("resources/MejorTorreta2Bloqueda.jpg")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
     if(!compramejorano.loadFromFile("resources/MejorEspadaBloqueda.jpg")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }

    if(!font.loadFromFile("resources/fuente/Marker Felt.ttf")){
         std::cerr <<"Error al cargar la fuente";
        exit(0);
    }
    dinero.setFont(font);


tipoTorreta=1;
monedas=200;

}

int mundo::getCoins(){
return monedas;
}

bool mundo::gastaCoins(int coins){
    if(monedas-coins<0){
        return false;
    }
    else{
        monedas = monedas - coins;
    }
    return true;
}

void mundo::addCoins(int coins){
   monedas = monedas + coins;

}

void mundo::cambiarTipoTorreta(int tipo){
    tipoTorreta=tipo;
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

void mundo::test(){

cout << enemigosEspera->size() << endl;
}

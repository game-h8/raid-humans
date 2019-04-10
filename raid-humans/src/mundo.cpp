#include "mundo.h"

mundo::mundo()
{
    //ctor
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

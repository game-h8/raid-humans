#include "StateMachine.h"

StateMachine::StateMachine()
{
    estado=1;
}

StateMachine::~StateMachine()
{
    //dtor
}

int StateMachine::getEstado(){

return estado;
}

bool StateMachine::getModo(){


return compra;
}

bool StateMachine::getColocando(){


return colocandoTurret;
}

void StateMachine::toggleModo(){

if(compra) compra = false;
else compra = true;


}

void StateMachine::toggleColocar(){

if(colocandoTurret) colocandoTurret = false;
else colocandoTurret = true;


}

void StateMachine::setEstado(int i){

    if(i>0&&i<=5)
    estado= i;

}




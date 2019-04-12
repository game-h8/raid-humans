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
void StateMachine::setEstado(int i){

    if(i>0&&i<=5)
    estado= i;
}




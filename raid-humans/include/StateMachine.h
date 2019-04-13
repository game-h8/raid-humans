#ifndef STATEMACHINE_H
#define STATEMACHINE_H


class StateMachine
{
    public:

        StateMachine();
        virtual ~StateMachine();
        void setEstado(int i);
        int getEstado();
        bool getModo();
        void toggleModo();
        void toggleColocar();
        bool getColocando();

    protected:

    private:
        int estado;
        bool compra = true;
        int ronda = 1;
        bool colocandoTurret = false;
};

#endif // STATEMACHINE_H

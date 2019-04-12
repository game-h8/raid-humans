#ifndef STATEMACHINE_H
#define STATEMACHINE_H


class StateMachine
{
    public:

        StateMachine();
        virtual ~StateMachine();
        void setEstado(int i);
        int getEstado();



    protected:

    private:
        int estado;
};

#endif // STATEMACHINE_H

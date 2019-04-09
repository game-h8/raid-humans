#include "../include/juego.h"




#define UPDATE_TICK_TIME 1000/15


juego::juego(Vector2u resolucion)
{
    //ctor
inicializar();
 ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "Raid humans");

 jugador= new player("resources/player.png" ,500,400);

    Clock clock;
    Clock updateCLock;
    Time tiempo = clock.getElapsedTime();





 while(ventana->isOpen()){

     Event event;
    while (ventana->pollEvent(event))
    {

        if (event.type == Event::Closed) ventana->close();
        if (Keyboard::isKeyPressed(Keyboard::F6))
            {
                 jugador->toggleDebug();
            }
    }
         if(clock.getElapsedTime().asMilliseconds() - tiempo.asMilliseconds() > UPDATE_TICK_TIME){


            update(updateCLock.restart().asSeconds());

            tiempo = clock.getElapsedTime();


         }
float timeElapsed=updateCLock.getElapsedTime().asMilliseconds();
float tiempoRefresco = UPDATE_TICK_TIME;                                   //Hay un bug que si utilizas el  UPDATE TIME directamente no hace la division bien

   float percentick=min(1.f,timeElapsed/tiempoRefresco);


    renderizar(percentick);




 }
 delete ventana;
 delete jugador;
}
/*
juego::~juego()
{
    //dtor


}
*/

void juego:: inicializar() { //inicializar las variables del juego



}


void juego:: update(float elapsedTime){

vector<int> inputs= getInputs();                //Funcion para coger los botones que se pulsan
jugador->calcularVelocidadPlayer(inputs,elapsedTime); //Calculamos la direccion de la velocidad dependiendo de las teclas pulsadas
                                                    //Calculamos la posicion inicial y final deljugador y lo movemos

}


void juego:: renderizar(float percentick){



ventana->clear();
jugador->render(percentick, *ventana);
ventana->display();


}

vector<int> juego::getInputs(){



vector<int> data;



            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                   data.push_back(4);                               //IZQUIERDA --> 4
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))    //DEREZHA --> 6
            {
                  data.push_back(6);
            }
            if (Keyboard::isKeyPressed(Keyboard::Up))       //ARRIBA --> 8
            {
                 data.push_back(8);
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))     //ABAJO --> 2
            {
                data.push_back(2);
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))    //ESCAPE --> 0
            {
                data.push_back(0);
            }

            if (Mouse::isButtonPressed(Mouse::Left)){
                data.push_back(5);
            }

            Vector2i position = Mouse::getPosition(*ventana);

            if(position.x > jugador->x){         //RATON MIRA DERECHA
               data.push_back(7);

            }else{
               data.push_back(9);                   //RATON MIRA IZQUIERDA
            }


    return data;
}

Vector2f juego::calcularVelocidadPlayer(vector<int> inputs){


    sf::Vector2f v;
v.x=0;
v.y=0;



    for (int i=0; i< inputs.size();i++){

        switch (inputs[i]){


        case 8:


            v.y-=kVel;


        break;
        case 4:

          jugador->pSprite.setTextureRect(sf::IntRect(4, 8, 40, 60));
            v.x-=kVel;

        break;
        case 6 :

         jugador->pSprite.setTextureRect(sf::IntRect(4, 8, 40, 60));                               //Escala por defecto
            v.x+=kVel;

        break;
        case 2 :


            v.y+=kVel;

        break;
        case 7 :

            jugador->pSprite.setScale(-1,1);
        break;
        case 9 :

            jugador->pSprite.setScale(1,1);
        break;




        }


    }
     return v;

}

#include <juego.h>

#define UPDATE_TICK_TIME 1000/15
#define SPAWN_SPEED 3000
#define kVel 100

using namespace std;

juego::juego(Vector2u resolucion)
{
    //ctor
inicializar();
 ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "Raid humans");
 jugador= new player("resources/sprites.png" ,500,400);

    Clock clock;
    Clock updateCLock;
    Time tiempo = clock.getElapsedTime();

    //variables de tiempo para el spawn
    Clock clockSpawn;
    Time tiempoSpawn = clock.getElapsedTime();

    enemigos ene1(100,100);
    enemigos ene2(100,100);
    enemigos ene3(100,100);
    enemigos ene4(100,100);

    enemigosEspera.push_back(ene1);
    enemigosEspera.push_back(ene2);
    enemigosEspera.push_back(ene3);
    enemigosEspera.push_back(ene4);

    /*for (int i=0;i<4;i++) {
        enemigosEspera[i] = enemigo(100,100);
    }*/


 while(ventana->isOpen()){

     Event event;
    while (ventana->pollEvent(event))
    {

        if (event.type == Event::Closed) ventana->close();

    }
         if(clock.getElapsedTime().asMilliseconds() - tiempo.asMilliseconds() > UPDATE_TICK_TIME){


            update(updateCLock.restart().asSeconds());
            tiempo = clock.getElapsedTime();


         }
         //temporizador para generar enemigos
         if(clockSpawn.getElapsedTime().asMilliseconds() - tiempoSpawn.asMilliseconds() > SPAWN_SPEED){

            tiempoSpawn = clockSpawn.getElapsedTime();
            if (enemigosEspera.empty()==false) {
                enemigosFuera.push_back(enemigosEspera.at(enemigosEspera.size()-1));
                enemigosEspera.pop_back();
            }
            //le damos un objetivo al enemigo
            Vector2f obj(100.f,700.f);
            enemigosFuera.at(enemigosFuera.size()-1).setObjetivo(obj);


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

/*void juego::meterEnemigosEspera() {

    enemigosEspera->push_back(*enemigo1);
    enemigosEspera->push_back(*enemigo2);
    enemigosEspera->push_back(*enemigo3);
    enemigosEspera->push_back(*enemigo4);

}*/

void juego:: update(float elapsedTime){

//moviento jugador
vector<int> inputs= getInputs();                //Funcion para coger los botones que se pulsan
Vector2f v = calcularVelocidadPlayer(inputs);   //Calculamos la direccion de la velocidad dependiendo de las teclas pulsadas
jugador->movePlayer(v,elapsedTime);            //Calculamos la posicion inicial y final deljugador y lo movemos

//movimiento enemigo
if (enemigosFuera.empty()==false) {
    for (int i=0;i<enemigosFuera.size();i++) {
        enemigosFuera.at(i).moveEnemy(elapsedTime);
    }
}

}


void juego:: renderizar(float percentick){



ventana->clear();

jugador->render(percentick, *ventana);

if (enemigosFuera.empty()==false) {
    for (int i=0;i<enemigosFuera.size();i++) {
        enemigosFuera.at(i).render(percentick, *ventana);
    }
}

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

         jugador->pSprite.setTextureRect(IntRect(0*75, 3*75, 75, 75));
            v.y-=kVel;


        break;
        case 4:

          jugador->pSprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
            v.x-=kVel;

        break;
        case 6 :

         jugador->pSprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));                               //Escala por defecto
            v.x+=kVel;

        break;
        case 2 :

         jugador->pSprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));
            v.y+=kVel;

        break;
        case 7 :

            jugador->pSprite.setScale(1,1);
        break;
        case 9 :

            jugador->pSprite.setScale(-1,1);
        break;




        }


    }
     return v;

}

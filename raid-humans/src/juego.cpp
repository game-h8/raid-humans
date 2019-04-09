<<<<<<< HEAD
#include "../include/juego.h"



#define SPAWN_SPEED 3000
#define SHOOT_SPEED 4000
#define UPDATE_TICK_TIME 1000/15
#define kVel 100

=======
#include <juego.h>
#include <cstddef>
#include <SFML/Graphics/Image.hpp>

#define UPDATE_TICK_TIME 1000/15
#define SPAWN_SPEED 3000
#define kVel 100

using namespace std;

>>>>>>> Enemigo(ataque,movimiento,yGenerar)
juego::juego(Vector2u resolucion)
{
    //ctor
inicializar();
 ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "Raid humans");
<<<<<<< HEAD
 jugador= new player("resources/player.png" ,500,400);
=======
 jugador= new player("resources/sprites.png" ,500,400);
>>>>>>> Enemigo(ataque,movimiento,yGenerar)

    Clock clock;
    Clock updateCLock;
    Time tiempo = clock.getElapsedTime();

<<<<<<< HEAD

=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)
    //variables de tiempo para el spawn
    Clock clockSpawn;
    Time tiempoSpawn = clock.getElapsedTime();

<<<<<<< HEAD
    enemigos ene1(100,100);
    enemigos ene2(100,100);
    enemigos ene3(100,100);
    enemigos ene4(100,100);
=======
    enemigo ene1(100,100);
    enemigo ene2(100,100);
    enemigo ene3(100,100);
    enemigo ene4(100,100);
>>>>>>> Enemigo(ataque,movimiento,yGenerar)

    enemigosEspera.push_back(ene1);
    enemigosEspera.push_back(ene2);
    enemigosEspera.push_back(ene3);
    enemigosEspera.push_back(ene4);

<<<<<<< HEAD
=======
    /*for (int i=0;i<4;i++) {
        enemigosEspera[i] = enemigo(100,100);
    }*/

>>>>>>> Enemigo(ataque,movimiento,yGenerar)

 while(ventana->isOpen()){

     Event event;
    while (ventana->pollEvent(event))
    {

        if (event.type == Event::Closed) ventana->close();
<<<<<<< HEAD
         if (Keyboard::isKeyPressed(Keyboard::F6))
            {
                 jugador->toggleDebug();
            }

=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)

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

<<<<<<< HEAD
            disparar();
         }



=======

         }
>>>>>>> Enemigo(ataque,movimiento,yGenerar)
float timeElapsed=updateCLock.getElapsedTime().asMilliseconds();
float tiempoRefresco = UPDATE_TICK_TIME;                                   //Hay un bug que si utilizas el  UPDATE TIME directamente no hace la division bien

   float percentick=min(1.f,timeElapsed/tiempoRefresco);

    renderizar(percentick);



 }
 delete ventana;
 delete jugador;
<<<<<<< HEAD

=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)
}
/*
juego::~juego()
{
    //dtor


}
*/

void juego:: inicializar() { //inicializar las variables del juego


}

<<<<<<< HEAD

void juego:: update(float elapsedTime){

vector<int> inputs= getInputs();                //Funcion para coger los botones que se pulsan
jugador->calcularVelocidadPlayer(inputs,elapsedTime); //Calculamos la posicion inicial y final deljugador y lo movemos



for(int i=0; i<vectorBalas.size(); i++){
    vectorBalas[i].disparar(elapsedTime);
    for (int j=0;j<enemigosFuera.size();j++) {
        vectorBalas[i].colision(enemigosFuera[j]);
    }
    if(!vectorBalas[i].viva){
        vectorBalas.erase(vectorBalas.begin()+i);
    }
cout<<"Tamano vectorBalas: " <<vectorBalas.size() <<endl;
}
=======
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
>>>>>>> Enemigo(ataque,movimiento,yGenerar)

//movimiento enemigo
if (enemigosFuera.empty()==false) {
    for (int i=0;i<enemigosFuera.size();i++) {
        enemigosFuera.at(i).moveEnemy(elapsedTime);
<<<<<<< HEAD
    }
}

=======
        enemigosFuera.at(i).ataque(jugador);
        if(enemigosFuera.at(i).ataca==true){
             if (!dTexture.loadFromFile("resources/hit.png")){
                cerr << "Error cargando la imagen del golpe resources/sprites.png" << endl;
                exit(0);

            }


            dSprite.setTexture(dTexture);
            dSprite.setOrigin(17,48/2);
            dSprite.setTextureRect(IntRect(0.1*35, 2.63*50, 28, 27));
            dSprite.setPosition(jugador->xlast,jugador->ylast+25);
        }else{
        }
    }
}



>>>>>>> Enemigo(ataque,movimiento,yGenerar)
}


void juego:: renderizar(float percentick){



ventana->clear();
<<<<<<< HEAD
dibujarSelector();

//Recorrer el vector de torretas y dibujar las torretas
for(int i=0; i<vectorTorreta.size(); i++)
    vectorTorreta[i].draw(*ventana);
for(int i=0; i<vectorBalas.size(); i++){
    vectorBalas[i].render(percentick, *ventana);
}
=======

>>>>>>> Enemigo(ataque,movimiento,yGenerar)
jugador->render(percentick, *ventana);

if (enemigosFuera.empty()==false) {
    for (int i=0;i<enemigosFuera.size();i++) {
        enemigosFuera.at(i).render(percentick, *ventana);
    }
}
<<<<<<< HEAD
=======

if (enemigosFuera.size()>0) {
    for (int i=0;i<enemigosFuera.size();i++) {
        if(enemigosFuera.at(i).ataca==true){
            ventana->draw(dSprite);
        }
    }
}




>>>>>>> Enemigo(ataque,movimiento,yGenerar)
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

<<<<<<< HEAD
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                data.push_back(5);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                addTorreta();
            }

=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)
            Vector2i position = Mouse::getPosition(*ventana);

            if(position.x > jugador->x){         //RATON MIRA DERECHA
               data.push_back(7);

            }else{
               data.push_back(9);                   //RATON MIRA IZQUIERDA
            }


    return data;
}

<<<<<<< HEAD

void juego::dibujarSelector(){
    //Dibujar selector en el mapa para poner la torreta donde marque

    //definir rectangulo, para selector
    sf::RectangleShape selector(sf::Vector2f(30.f, 32.f));
    sf::Color trasnparente(0, 0, 0, 1); //Cuadrado transparente
    selector.setFillColor(trasnparente);
    //Pintar borde del rectangulo, que sera e selector
    selector.setOutlineThickness(2.f);
    selector.setOutlineColor(sf::Color(255, 255, 255)); //Color blanco

        //Obtener coordenadas de la ventana
        sf::Vector2i localPosition = sf::Mouse::getPosition(*ventana);
        int posicionX = localPosition.x;
        int posicionY = localPosition.y;

        //Obtener parte entera de la division
        int i = (posicionX/32);
        int j = (posicionY/32);

        //Dibujar el selector en el cuadrado de la matriz
        selector.setPosition(i*32.f ,j*32.f);

        ventana->draw(selector);


}

void juego::addTorreta(){

    //Obtener coordenadas de la ventana
    sf::Vector2i localPosition = sf::Mouse::getPosition(*ventana);
    int posicionX = localPosition.x;
    int posicionY = localPosition.y;

    //Obtener parte entera de la division
    int i = (posicionX/32);
    int j = (posicionY/32);

    //CAMBIAR CUANDO TENGAMOS EL MAPA
    if(i >= 0 && j >= 0 && i <= 24 && j <= 18){
        //Crea la clase torreta dandole un tamanio
        Torreta* torreta = new Torreta("ballesta.png");
        //Coloca la torreta en una posicion llamando a una funcion que hemos creado en la clase torreta setPos
        torreta->setPos(sf::Vector2f(i*32.f ,j*32.f));
        //Anade la torreta creada al vector de torretas
        vectorTorreta.push_back(*torreta);
    }

}

void juego::disparar(){

    //Recorro el vector de torretas, las cuales dispararan al enemigo mas cercano
    for(int i=0; i<vectorTorreta.size(); i++){
        float angle=0;
        float enemigoX=0;//Variables para pasar a la nueva bala, con la pos del enemigo mas cercano
        float enemigoY=0;
        float dist=10000;
        /*FUNCION PARA CALCULAR EL ENEMIGO MAS CERCANO cogiendo el vector de los enemigos Y PASARLE LA POSICION A LA NUEVA BALA
          IF HAY ALGUN ENEMIGO le paso la posicion ELSE no creo la bala */
        if(!enemigosFuera.empty()){//Si hay enemigos
            for(int j=0; j<enemigosFuera.size(); j++){//Recorro el vector de enemigos
                if(enemigosFuera[j].x>0){//Si en esa pos del vector hay un enemigo
                    //Calcular distancia entre enemigo y torreta
                    float newDist=sqrt(pow(vectorTorreta[i].getX()-enemigosFuera[j].x,2) + pow(vectorTorreta[i].getY()-enemigosFuera[j].y,2));
                    if(newDist < dist){
                        dist=newDist;//si la nueva distancia es menor que la anterior, sera la nueva distancia
                        enemigoX=enemigosFuera[j].x;//Asignamos las coordenadas de ese enemigo a nuestras variables
                        enemigoY=enemigosFuera[j].y;
                    }
                }
            }
            Bala * nuevaBala = new Bala(enemigoX, enemigoY);
            angle = nuevaBala->setPos(sf::Vector2f(vectorTorreta[i].getX(), vectorTorreta[i].getY()));
            vectorBalas.push_back(*nuevaBala);
            vectorTorreta[i].rotarTorreta(angle);
        }
    }
=======
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
>>>>>>> Enemigo(ataque,movimiento,yGenerar)

}

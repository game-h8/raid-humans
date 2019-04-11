#include "../include/juego.h"



#define SPAWN_SPEED 4000
#define SHOOT_SPEED 4000
#define UPDATE_TICK_TIME 1000/15
#define kVel 100


#include <SFML/Graphics.hpp>
#include <iostream>
#include "tinyxml2.h"
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
juego::juego(Vector2u resolucion)
{
    //ctor
inicializar();


//creo mapa
 mapa = new Mapa("resources/untitled2.tmx", "resources/PathAndObjects.png");
 ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "Raid humans");
 jugador= new player("resources/player.png" ,500,400);
 monedas=0;


 mundo::getMundo()->ventana=ventana;
 mundo::getMundo()->jugador=jugador;
 mundo::getMundo()->mapa=mapa;


    Clock clock;
    Clock updateCLock;
    Time tiempo = clock.getElapsedTime();


    //variables de tiempo para el spawn
    Clock clockSpawn;
    Time tiempoSpawn =  seconds(3.f);

    //variables de tiempo para la bala
    Clock clockBala;
    Time tiempoBala = clock.getElapsedTime();

    enemigos ene1(100,100);
    enemigos ene2(100,100);
    enemigos ene3(100,100);
    enemigos ene4(100,100);

    Moneda m1(100,300,10);
    vectorMonedas.push_back(m1);
    Moneda m2(200,200,150);
    vectorMonedas.push_back(m2);
    Moneda m3(400,300,490);
    vectorMonedas.push_back(m3);
    Moneda m4(500,200,4000);
    vectorMonedas.push_back(m4);
    Moneda m5(500,500,900);
    vectorMonedas.push_back(m5);
    Moneda m6(100,200,1500);
    vectorMonedas.push_back(m6);

    enemigosEspera.push_back(ene1);
   enemigosEspera.push_back(ene2);
   // enemigosEspera.push_back(ene3);
   // enemigosEspera.push_back(ene4);


    //variables de tiempo para el ataque
    Clock clockAttack;
    Time tiempoAttack = seconds(1.f);


 while(ventana->isOpen()){

     Event event;
    while (ventana->pollEvent(event))
    {

        if (event.type == Event::Closed) {

             delete jugador;
             delete mapa;
             ventana->close();
            delete ventana;
        }
         if (Keyboard::isKeyPressed(Keyboard::F6))
            {
                 mundo::getMundo()->toggleDebug();
                 mundo::getMundo()->test();
            }


    }
         if(clock.getElapsedTime().asMilliseconds() - tiempo.asMilliseconds() > UPDATE_TICK_TIME){


            update(updateCLock.restart().asSeconds());
            tiempo = clock.getElapsedTime();


         }
         //temporizador para generar enemigos
         if(clockSpawn.getElapsedTime() > tiempoSpawn){

            clockSpawn.restart();

            if (enemigosEspera.empty()==false) {
                enemigosFuera.push_back(enemigosEspera.at(enemigosEspera.size()-1));
                enemigosEspera.pop_back();
            }
            if (enemigosFuera.empty()==false) {
                for (int i=0;i<enemigosFuera.size()&&i<4;i++) {
                    enemigosFuera.at(i).atacaTorretaCercana(vectorTorreta);
                }
}
            //le damos un objetivo al enemigo


         }

          // los enemigos comprueban el ataque
         if(clockAttack.getElapsedTime() > tiempoAttack){

            clockAttack.restart();

            if (enemigosFuera.empty()==false) {
                for (int i=0;i<enemigosFuera.size();i++) {
                    enemigosFuera.at(i).ataque(jugador);
                    if(enemigosFuera.at(i).ataca==true){
                       // if (!dTexture.loadFromFile("resources/hit.png")){
                         //   cerr << "Error cargando la imagen del golpe resources/sprites.png" << endl;
                         //   exit(0);
                      //  }
                      //enemigosFuera.at(i).eSprite.setColor(Color(255,0,0,155));

                    }else{
                      //enemigosFuera.at(i).eSprite.setColor(Color(255,255,255,255));
                    }
                }
            }

         }

        //temporizador para generar balas
         if(clockBala.getElapsedTime().asMilliseconds() - tiempoBala.asMilliseconds() > SHOOT_SPEED){
            tiempoBala = clockBala.getElapsedTime();
            disparar();
         }



float timeElapsed=updateCLock.getElapsedTime().asMilliseconds();
float tiempoRefresco = UPDATE_TICK_TIME;                                   //Hay un bug que si utilizas el  UPDATE TIME directamente no hace la division bien

   float percentick=min(1.f,timeElapsed/tiempoRefresco);

    renderizar(percentick);



 }


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
jugador->calcularVelocidadPlayer(inputs,elapsedTime); //Calculamos la posicion inicial y final deljugador y lo movemos



for(int i=0; i<vectorBalas.size(); i++){
    vectorBalas[i].disparar(elapsedTime);
    for (int j=0;j<enemigosFuera.size();j++) {
        vectorBalas[i].colision(enemigosFuera[j]);
    }
    if(!vectorBalas[i].viva){
        vectorBalas.erase(vectorBalas.begin()+i);
    }
//cout<<"Tamano vectorBalas: " <<vectorBalas.size() <<endl;
}


//QUE ES ESTO? NO HACE NADA///////////////////////////////////////////////////////////////////////////////////
//movimiento enemigo
if (enemigosFuera.empty()==false) {
    for (int i=0;i<enemigosFuera.size();i++) {
        enemigosFuera.at(i).moveEnemy(elapsedTime, enemigosFuera, vectorTorreta, i);


            dSprite.setTexture(dTexture);
            dSprite.setOrigin(17,48/2);
            dSprite.setTextureRect(IntRect(0.1*35, 2.63*50, 28, 27));
            dSprite.setPosition(jugador->xlast,jugador->ylast+25);
        }
}
recogerMoneda();

for(int i = 0; i < vectorTorreta.size(); i++){
    vectorTorreta[i].dibujarSprite();
}

}
//ataque de los enemigos


void juego:: renderizar(float percentick){



ventana->clear();

mapa->setActivateLayer(0);
mapa->drawMapa(*ventana);

dibujarSelector();

//Recorrer el vector de torretas y dibujar las torretas
for(int i=0; i<vectorTorreta.size(); i++)
    vectorTorreta[i].draw(*ventana);
for(int i=0; i<vectorBalas.size(); i++){
    vectorBalas[i].render(percentick, *ventana);
}
jugador->render(percentick, *ventana);

if (enemigosFuera.empty()==false) {
    for (int i=0;i<enemigosFuera.size();i++) {
        enemigosFuera.at(i).render(percentick, *ventana);
    }
}

if (enemigosFuera.size()>0) {
    for (int i=0;i<enemigosFuera.size();i++) {
        if(enemigosFuera.at(i).ataca==true){
            ventana->draw(dSprite);
        }
    }
}

for(int i=0; i<vectorMonedas.size(); i++){
    vectorMonedas[i].render(*ventana);
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

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                data.push_back(5);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                addTorreta();
            }

            Vector2i position = Mouse::getPosition(*ventana);

            if(position.x > jugador->x){         //RATON MIRA DERECHA
               data.push_back(7);

            }else{
               data.push_back(9);                   //RATON MIRA IZQUIERDA
            }


    return data;
}


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
    bool existe = false;

    //Obtener parte entera de la division
    int i = (posicionX/32);
    int j = (posicionY/32);

    for(int k = 0; k < vectorTorreta.size();k++){
        if(vectorTorreta[k].getX()/32 == i && vectorTorreta[k].getY()/32 == j){
            existe = true;
        }
    }

    //CAMBIAR CUANDO TENGAMOS EL MAPA
    if(i >= 0 && j >= 0 && i <= 24 && j <= 18 && !existe){
        //Crea la clase torreta dandole un tamanio
        Torreta* torreta = new Torreta();
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
                    if(dist<=300){
                        enemigoX=enemigosFuera[j].x;//Asignamos las coordenadas de ese enemigo a nuestras variables
                        enemigoY=enemigosFuera[j].y;
                    }
                    }
                }
            }
            if(dist<=300){
                Bala * nuevaBala = new Bala(enemigoX, enemigoY);
                angle = nuevaBala->setPos(sf::Vector2f(vectorTorreta[i].getX(), vectorTorreta[i].getY()));
                vectorBalas.push_back(*nuevaBala);
                vectorTorreta[i].rotarTorreta(angle);
            }
        }
    }

}
void juego::recogerMoneda(){
    for(int i=0; i<vectorMonedas.size(); i++){
        if(vectorMonedas[i].hitbox.getGlobalBounds().intersects(jugador->hitbox.getGlobalBounds())){
            vectorMonedas.erase(vectorMonedas.begin()+i);
            monedas+=vectorMonedas[i].valor;

        }
    }


}
vector<Torreta> juego::getTorretas() {
    return vectorTorreta;
}

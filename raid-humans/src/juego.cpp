#include "../include/juego.h"




#define UPDATE_TICK_TIME 1000/15
#define kVel 100

juego::juego(Vector2u resolucion)
{
    //ctor
inicializar();
 ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "Raid humans");
 jugador= new player("resources/sprites.png" ,500,400);

    Clock clock;
    Clock updateCLock;
    Time tiempo = clock.getElapsedTime();





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

    //INICIO PARTE DE TORRETA Y SELECTOR Y BALAS-------------------------------



    bool disparando = false;
    //FIN PARTE DE TORRETA Y SELECTOR Y BALAS--------------------------------

}


void juego:: update(float elapsedTime){

vector<int> inputs= getInputs();                //Funcion para coger los botones que se pulsan
Vector2f v = calcularVelocidadPlayer(inputs);   //Calculamos la direccion de la velocidad dependiendo de las teclas pulsadas
jugador->movePlayer(v,elapsedTime);             //Calculamos la posicion inicial y final deljugador y lo movemos
for(int i=0; i<vectorBalas.size(); i++){
    vectorBalas[i].disparar(elapsedTime);
    //vectorBalas[i].perseguir(enemigo.getPosX(), enemigo.getPosY());
    //Si la bala colisiona con el enemigo, muere
    //enemigo.colisionBala(vectorBalas[i]);
}

}


void juego:: renderizar(float percentick){



ventana->clear();
dibujarSelector();

//Recorrer el vector de torretas y dibujar las torretas
for(int i=0; i<vectorTorreta.size(); i++)
    vectorTorreta[i].draw(*ventana);

for(int i=0; i<vectorBalas.size(); i++){
    vectorBalas[i].render(percentick, *ventana);
    //vectorBalas[i].perseguir(enemigo.getPosX(), enemigo.getPosY());
    //Si la bala colisiona con el enemigo, muere
    //enemigo.colisionBala(vectorBalas[i]);
}
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
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                addTorreta();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                disparar();
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

    //Crea la clase torreta dandole un tamanio
    Torreta* torreta = new Torreta("ballesta.png");
    //Coloca la torreta en una posicion llamando a una funcion que hemos creado en la clase torreta setPos
    torreta->setPos(sf::Vector2f(i*32.f ,j*32.f));
    //Anade la torreta creada al vector de torretas
    vectorTorreta.push_back(*torreta);

}

void juego::disparar(){

    //Recorro el vector de torretas, las cuales dispararan al centro del mapa cada x tiempo
    for(int i=0; i<vectorTorreta.size(); i++){
        Bala * nuevaBala = new Bala(jugador->x, jugador->y);
        nuevaBala->setPos(sf::Vector2f(vectorTorreta[i].getX(), vectorTorreta[i].getY()));
        vectorBalas.push_back(*nuevaBala);
    }

}

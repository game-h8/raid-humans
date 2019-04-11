#include "../include/enemigos.h"

using namespace sf;
using namespace std;

enemigos::enemigos() {
    x=0;
    y=0;
    xlast=0;
    ylast=0;
    saludEnemigo=0;
    danioEnemigo=0;




}

enemigos::enemigos(const enemigos& E) {


    eSprite=E.eSprite;
    hitbox=E.hitbox;
    x=E.x;
    y=E.y;
    xlast=E.xlast;
    ylast=E.ylast;
    vel=E.vel;
    saludEnemigo=E.saludEnemigo;
    danioEnemigo=E.danioEnemigo;
    estado=1;


}

enemigos::enemigos(float x2, float y2) {



    eSprite.setTexture(mundo::getMundo()->eTexture);
    eSprite.setOrigin(17,48/2);   // ahora es fija pero debera ser la que mande el spawn
    eSprite.setTextureRect(IntRect(3, 290, 59, 88));




    x=x2;
    y=y2;
    xlast=x2;
    ylast=y2;


      hitbox.setSize(Vector2f(59,88));
    hitbox.setFillColor(Color(255,0,0,155));
    hitbox.setOrigin(eSprite.getGlobalBounds().width/2-17,eSprite.getGlobalBounds().height/2-24);
    hitbox.setPosition(Vector2f(x,y));


    eSprite.setPosition(x,y);

}

enemigos::~enemigos() {

}


void enemigos::moveEnemy(float time, vector<enemigos> ene, vector<Torreta> torres, int a) {

    xlast=x;
    ylast=y;
    bool colision=false;
    Vector2f pos;

    if(atacaTorre==false) {
        for(int i=0; i<ene.size()&&colision==false; i++){
            for(int j=0; i<torres.size()&&colision==false; i++){
                if(i!=a){
                    if(hitbox.getGlobalBounds().intersects(ene.at(i).hitbox.getGlobalBounds())){
                        colision=true;
                    }
                    if(hitbox.getGlobalBounds().intersects(torres.at(j).getSprite().getGlobalBounds())) {
                        atacaTorre=true;
                    }
                }
            }
        }
        if(colision==false){
            if(x < objetivo.x && y < objetivo.y) {
            x=x+velocidad*time;
            y=y+velocidad*time;

            }
            if(x > objetivo.x && y < objetivo.y) {
                x=x-velocidad*time;
                y=y+velocidad*time;

            }
            if(x < objetivo.x && y > objetivo.y) {
                x=x+velocidad*time;
                y=y-velocidad*time;

            }
            if(x > objetivo.x && y > objetivo.y) {
                x=x-velocidad*time;
                y=y-velocidad*time;

            }
        }else{
            /*if(x < objetivo.x && y < objetivo.y) {
            x=x+(velocidad*0.5)*time;
            y=y+velocidad*time;

            }
            if(x > objetivo.x && y < objetivo.y) {
                x=x-(velocidad*0.5)*time;
                y=y+velocidad*time;

            }
            if(x < objetivo.x && y > objetivo.y) {
                x=x+(velocidad*0.5)*time;
                y=y-velocidad*time;

            }
            if(x > objetivo.x && y > objetivo.y) {
                x=x-(velocidad*0.5)*time;
                y=y-velocidad*time;

            }*/
            x=x+10;
            y=y+20;
        }
        //eSprite.getGlobalBounds().top;

        /*Vector2f pos;
        pos.x=x;
        pos.y=y;*/
    }
        eSprite.setPosition(x,y);
        hitbox.setScale(eSprite.getScale());
        hitbox.setPosition(x,y);

        movsprites();
}

void enemigos::colisionEnemigos(Vector2f ene){

}

bool enemigos::ataque(player * p){
    if(ataca==false){
        if(hitbox.getGlobalBounds().intersects(p->hitbox.getGlobalBounds())){
            ataca=true;
        }
    }
    else{
        if(!hitbox.getGlobalBounds().intersects(p->hitbox.getGlobalBounds())){
            ataca=false;
        }
    }
    return ataca;
}

void enemigos::setObjetivo(Vector2f obj) {
    objetivo = obj;
}
sf::FloatRect enemigos::getGlobal(){
    return eSprite.getGlobalBounds();
}
void enemigos::render(float ticks, RenderWindow &ventana) {

eSprite.setPosition(xlast*(1-ticks) + x*ticks,ylast*(1-ticks)+y*ticks);
ventana.draw(eSprite);
ventana.draw(hitbox);


}

void enemigos::atacaTorretaCercana(vector<Torreta> vecTor) {
    vector<Torreta> torretas = vecTor;
    float masCercanaX=0;
    float masCercanaY=0;
    float posibleResultado=0;
    float mejorResultado=9999;
    int posMasCercana=0;

    if (torretas.size()>0) {
            for (int i=0;i<torretas.size();i++) {
                posibleResultado=fabs(fabs((x-torretas.at(i).getX()))-fabs((y-torretas.at(i).getY())));

                if (posibleResultado<mejorResultado) {
                    posMasCercana=i;
                    mejorResultado=posibleResultado;
                }
            }
            masCercanaX=torretas.at(posMasCercana).getX();
            masCercanaY=torretas.at(posMasCercana).getY();
            Vector2f seleccionada(masCercanaX,masCercanaY);
            objetivo=seleccionada;
            if(objetivo.x>x){
                 eSprite.setScale(-1,1);
            }
            cout<<"distancia en x"<<(abs((int)objetivo.x)-abs((int)x))<<"distancia en y"<<(abs((int)objetivo.y)-abs((int)y))<<endl;


            if((abs((int)objetivo.x)-abs((int)x))<22 &&  (abs((int)objetivo.y)-abs((int)y))<50){


                estado=2;

            }
        }
}
void enemigos::atacaJugador(player &jugador) {
    objetivo=jugador.pSprite.getPosition();
}
void enemigos:: movsprites(){






    switch (estado){

    case 0:

        break;

        case 1:

            if(timeenemigo.getElapsedTime().asMilliseconds()<200){
                    eSprite.setTextureRect(IntRect(3, 290, 59, 88));
             }
              else if(timeenemigo.getElapsedTime().asMilliseconds()<400){
                    eSprite.setTextureRect(sf::IntRect(63, 290, 59, 88));
             }


              else{
             timeenemigo.restart();
             }
             break;

        case 2:

             if(timeenemigo.getElapsedTime().asMilliseconds()<200){
                    eSprite.setTextureRect(IntRect(2, 96, 59, 98));
             }
              else if(timeenemigo.getElapsedTime().asMilliseconds()<400){
                    eSprite.setTextureRect(sf::IntRect(118, 96, 45, 98));
             }
              else if(timeenemigo.getElapsedTime().asMilliseconds()<600){
                     eSprite.setOrigin(60,eSprite.getOrigin().y);
                     //hitbox.setOrigin(eSprite.getOrigin());

                    eSprite.setTextureRect(sf::IntRect(167, 96, 99, 98));

             }

             else if(timeenemigo.getElapsedTime().asMilliseconds()<800){

                    eSprite.setTextureRect(sf::IntRect(272, 96, 99, 98));

             }


             else if(timeenemigo.getElapsedTime().asMilliseconds()<1000){

                    eSprite.setTextureRect(sf::IntRect(108, 195, 90, 90));
             }


             else if(timeenemigo.getElapsedTime().asMilliseconds()<1200){
                    eSprite.setTextureRect(sf::IntRect(296, 190, 90, 90));
             }

             else{
                hitbox.setOrigin(eSprite.getGlobalBounds().width/2,eSprite.getGlobalBounds().height/2);
                  eSprite.setTextureRect(IntRect(3, 290, 59, 98));
                    eSprite.setOrigin(hitbox.getOrigin());
             timeenemigo.restart();

             }

           break;


    }

}

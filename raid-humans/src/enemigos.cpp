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
    colision=E.colision;
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

    colision.setSize(Vector2f(15,10));
    colision.setFillColor(Color(255,255,0,155));
    colision.setOrigin(eSprite.getGlobalBounds().width/2,eSprite.getGlobalBounds().height/2-50);
    colision.setPosition(Vector2f(x,y));


    eSprite.setPosition(x,y);

}

enemigos::~enemigos() {

}


void enemigos::moveEnemy(float time, vector<enemigos> ene, vector<Torreta> torres, int a) {

    xlast=x;
    ylast=y;
    bool choca=false;
    Vector2f pos;

    if(atacaTorre==false) {
        for(int i=0; i<ene.size()&&choca==false; i++){
            //for(int j=0; i<torres.size()&&colision==false; i++){
                if(i!=a){
                    if(colision.getGlobalBounds().intersects(ene.at(i).colision.getGlobalBounds())){
                        choca=true;
                    }
                    if(ene.at(i).atacaTorre==true) {
                        choca=true;
                    }
                }
            //}
        }
        if(choca==false && atacaTorre==false){
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
            if (atacaTorre==false) {
                if(x < objetivo.x && y < objetivo.y) {
                    x=x-2*time;
                    y=y-3*time;

                }
                if(x > objetivo.x && y < objetivo.y) {
                    x=x+2*time;
                    y=y-3*time;

                }
                if(x < objetivo.x && y > objetivo.y) {
                    x=x-2*time;
                    y=y+3*time;


                }
                if(x > objetivo.x && y > objetivo.y) {
                    x=x+2*time;
                    y=y+3*time;

                }
            }
        }
        //eSprite.getGlobalBounds().top;

        /*Vector2f pos;
        pos.x=x;
        pos.y=y;*/
    }
        eSprite.setPosition(x,y);
        hitbox.setScale(eSprite.getScale());
        hitbox.setPosition(x,y);
        colision.setPosition(x,y);

        movsprites();
}

void enemigos::colisionEnemigos(Vector2f ene){

}

bool enemigos::ataque(player * p, vector<Torreta> torres){
    if(ataca==false){
        if(hitbox.getGlobalBounds().intersects(p->hitbox.getGlobalBounds())){
            ataca=true;
        }
        if (ataca==false) {
            if (torres.empty()==false) {
                for(int i=0;i<torres.size();i++) {
                    if (hitbox.getGlobalBounds().intersects(torres.at(i).getSprite().getGlobalBounds())) {
                        ataca=true;
                    }

                }
            }
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
ventana.draw(colision);
if(mundo::getMundo()->getDebug()){
   ventana.draw(hitbox);

}
//ventana.draw(hitbox);
//ventana.draw(colision);



}

void enemigos::atacaTorretaCercana(vector<Torreta> vecTor) {
    vector<Torreta>* torretas = mundo::getMundo()->vectorTorreta ;

    float masCercanaX=0;
    float masCercanaY=0;
    float posibleResultado=0;
    float mejorResultado=9999;
    int posMasCercana=0;

    if (torretas->size()>0) {
            cout<<"numero de torretas"<<torretas->size()<<endl;
            for (int i=0;i<torretas->size();i++) {
                posibleResultado=fabs(fabs((x-torretas->at(i).getX()))-fabs((y-torretas->at(i).getY())));

                if (posibleResultado<mejorResultado) {
                    posMasCercana=i;
                    mejorResultado=posibleResultado;
                }
            }
            masCercanaX=torretas->at(posMasCercana).getX();
            masCercanaY=torretas->at(posMasCercana).getY();
            Vector2f seleccionada(masCercanaX,masCercanaY);
            objetivo=seleccionada;
            if(objetivo.x>x){
                 eSprite.setScale(-1,1);
            }
            cout<<"distancia en x"<<(abs((int)objetivo.x)-abs((int)x))<<"distancia en y"<<(abs((int)objetivo.y)-abs((int)y))<<endl;
            if (hitbox.getGlobalBounds().intersects(torretas->at(posMasCercana).getSprite().getGlobalBounds())) {
                atacaTorre=true;
            cout<<"vida de la torreta"<<mundo::getMundo()->vectorTorreta->at(posMasCercana).vida<<endl;

               if (mundo::getMundo()->vectorTorreta->at(posMasCercana).enemigohit(100) && timeenemigo.getElapsedTime().asMilliseconds()>600){

                mundo::getMundo()->vectorTorreta->erase(mundo::getMundo()->vectorTorreta->begin()+posMasCercana);
               }


            }

        }
}
void enemigos::atacaJugador(player &jugador) {
    objetivo=jugador.pSprite.getPosition();
}
//Hitplayer es cuando el jugador le ataca, devuelve true si muere
bool enemigos::playerHit(float dano){

    bool muerto=false;

if(invulnerable==false){
    if(vida-dano<=0) {
       // muere();
        mundo::getMundo()->vectorMonedas->push_back(Moneda(x,y,money));
       muerto=true;

    }
    else{
        vida=vida-dano;
        cout<<"vidaaaa"<<vida<<endl;
        timeInvul.restart();
        invulnerabilidad();
        invulnerable = true;
        }
    }
    return muerto;
}

void enemigos::invulnerabilidad(){


     if (invulnerable){
     eSprite.setColor(Color(255,0,0,155));

         if(timeInvul.getElapsedTime().asMilliseconds()>=200){

             eSprite.setColor(Color(255,255,255,255));
             invulnerable=false;
        }

    }

}

bool enemigos::balaHit(float dano){

    bool muerto=false;


    if(vida-dano<=0) {
       mundo::getMundo()->vectorMonedas->push_back(Moneda(x,y,money));
       muerto=true;

    }
    else{
        vida=vida-dano;

        timedanobala.restart();
        eSprite.setColor(Color(255,0,0,155));
        }

    return muerto;
}

void enemigos::danobala(){




         if(timedanobala.getElapsedTime().asMilliseconds()>=200){

             eSprite.setColor(Color(255,255,255,255));

        }



}

void enemigos:: movsprites(){

    if (atacaTorre==true) {
        estado=2;
    }






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
                    colision.setPosition(x,y);
             }
              else if(timeenemigo.getElapsedTime().asMilliseconds()<400){
                    eSprite.setTextureRect(sf::IntRect(118, 96, 45, 98));
             }
              else if(timeenemigo.getElapsedTime().asMilliseconds()<600){
                     eSprite.setOrigin(60,eSprite.getOrigin().y);
                     //hitbox.setOrigin(eSprite.getOrigin());
                     colision.setPosition(x,y);

                    eSprite.setTextureRect(sf::IntRect(167, 96, 99, 98));

             }

             else if(timeenemigo.getElapsedTime().asMilliseconds()<800){

                    eSprite.setTextureRect(sf::IntRect(272, 96, 99, 98));
                    colision.setPosition(x,y);

             }


             else if(timeenemigo.getElapsedTime().asMilliseconds()<1000){

                    eSprite.setTextureRect(sf::IntRect(108, 195, 90, 90));
                    colision.setPosition(x,y);
             }


             else if(timeenemigo.getElapsedTime().asMilliseconds()<1200){
                    eSprite.setTextureRect(sf::IntRect(296, 190, 90, 90));
                    colision.setPosition(x,y);
             }

             else{
                hitbox.setOrigin(eSprite.getGlobalBounds().width/2,eSprite.getGlobalBounds().height/2);
                colision.setPosition(x,y);
                  eSprite.setTextureRect(IntRect(3, 290, 59, 98));
                    eSprite.setOrigin(hitbox.getOrigin());
             timeenemigo.restart();

             }

           break;


    }

}

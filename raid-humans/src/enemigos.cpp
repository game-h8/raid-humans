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
    hitbox= E.hitbox;
    eTexture=E.eTexture;
    eSprite=E.eSprite;
    x=E.x;
    y=E.y;
    xlast=E.xlast;
    ylast=E.ylast;
    vel=E.vel;
    saludEnemigo=E.saludEnemigo;
    danioEnemigo=E.danioEnemigo;
}

enemigos::enemigos(float x2, float y2) {


    if (!eTexture.loadFromFile("resources/zombie.png"))
    {
        cerr << "Error cargando la imagen del enemigo resources/sprites.png" << endl;
        exit(0);

    }


    eSprite.setTexture(eTexture);
    eSprite.setOrigin(17,48/2);   // ahora es fija pero debera ser la que mande el spawn
    eSprite.setTextureRect(IntRect(0*35, 0*48, 35, 48));


    x=x2;
    y=y2;
    xlast=x2;
    ylast=y2;



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
                    if(eSprite.getGlobalBounds().intersects(ene.at(i).eSprite.getGlobalBounds())){
                        colision=true;
                    }
                    if(eSprite.getGlobalBounds().intersects(torres.at(j).getSprite().getGlobalBounds())) {
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
}

void enemigos::colisionEnemigos(Vector2f ene){

}

bool enemigos::ataque(player * p){
    if(ataca==false){
        if(eSprite.getGlobalBounds().intersects(p->pSprite.getGlobalBounds())){
            ataca=true;
        }
    }
    else{
        if(!eSprite.getGlobalBounds().intersects(p->pSprite.getGlobalBounds())){
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
        }
}
void enemigos::atacaJugador(player &jugador) {
    objetivo=jugador.pSprite.getPosition();
}

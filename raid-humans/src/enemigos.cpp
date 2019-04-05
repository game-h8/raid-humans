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


Vector2f enemigos::moveEnemy(float time) {
 //std::cout << "p--> x:"<< pos.x <<" y:"<< pos.y <<std::endl;
 // std::cout << "v--> x:"<< vel.x <<" y:"<< vel.y <<std::endl;
   // std::cout << "T--> "<< time <<" seg" <<std::endl;

    xlast=x;
    ylast=y;

    if(x <= objetivo.x && y <= objetivo.y) {
        x=x+velocidad*time;
        y=y+velocidad*time;




                /*if(eSprite.getPosition().x>=objetivo.x && eSprite.getPosition().y>=objetivo.y) {
                    llega=true;
                }*/
    }
    if(x >= objetivo.x && y <= objetivo.y) {
        x=x+velocidad*time;
        y=y+velocidad*time;

                /*if(eSprite.getPosition().x>=objetivo.x && eSprite.getPosition().y>=objetivo.y) {
                    llega=true;
                }*/
    }
    if(x <= objetivo.x && y >= objetivo.y) {
        x=x+velocidad*time;
        y=y+velocidad*time;

                /*if(eSprite.getPosition().x>=objetivo.x && eSprite.getPosition().y>=objetivo.y) {
                    llega=true;
                }*/
    }
    if(x >= objetivo.x && y >= objetivo.y) {
        x=x+velocidad*time;
        y=y+velocidad*time;

                /*if(eSprite.getPosition().x>=objetivo.x && eSprite.getPosition().y>=objetivo.y) {
                    llega=true;
                }*/
    }
    Vector2f pos;
    pos.x=xlast;
    pos.y=ylast;
    eSprite.setPosition(pos);
    return pos;


}

void enemigos::setObjetivo(Vector2f obj) {
    objetivo = obj;
}

void enemigos::render(float ticks, RenderWindow &ventana) {

eSprite.setPosition(xlast*(1-ticks) + x*ticks,ylast*(1-ticks)+y*ticks);
ventana.draw(eSprite);
}

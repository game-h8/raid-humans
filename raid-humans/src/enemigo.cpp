<<<<<<< HEAD
#include <enemigo.h>
=======
#include "enemigo.h"
>>>>>>> Enemigo(ataque,movimiento,yGenerar)

using namespace sf;
using namespace std;

enemigo::enemigo() {
<<<<<<< HEAD
    hitbox=nullptr;
    eTexture=nullptr;
    eSprite=nullptr;
=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)
    x=0;
    y=0;
    xlast=0;
    ylast=0;
<<<<<<< HEAD
    vel=nullptr;
=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)
    saludEnemigo=0;
    danioEnemigo=0;
}

enemigo::enemigo(const enemigo& E) {
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

enemigo::enemigo(float x2, float y2) {


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

enemigo::~enemigo() {

}


<<<<<<< HEAD
Vector2f enemigo::moveEnemigo(Vector2f v , float time) {
=======
Vector2f enemigo::moveEnemy(float time) {
>>>>>>> Enemigo(ataque,movimiento,yGenerar)
 //std::cout << "p--> x:"<< pos.x <<" y:"<< pos.y <<std::endl;
 // std::cout << "v--> x:"<< vel.x <<" y:"<< vel.y <<std::endl;
   // std::cout << "T--> "<< time <<" seg" <<std::endl;

<<<<<<< HEAD
xlast=x;
ylast=y;



    vel.x=v.x;
    vel.y=v.y;
    x=x+vel.x*time ;
    y=y +vel.y*time ;





Vector2f pos;
pos.x=xlast;
pos.y=ylast;
 pSprite.setPosition(pos);
    return pos;



}

void enemigo::render(float ticks, RenderWindow &ventana) {
=======
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

bool enemigo::ataque(player * p){
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

void enemigo::setObjetivo(Vector2f obj) {
    objetivo = obj;
}

void enemigo::render(float ticks, RenderWindow &ventana) {
    //animacion
    int state=0;

>>>>>>> Enemigo(ataque,movimiento,yGenerar)

eSprite.setPosition(xlast*(1-ticks) + x*ticks,ylast*(1-ticks)+y*ticks);
ventana.draw(eSprite);
}
<<<<<<< HEAD

=======
>>>>>>> Enemigo(ataque,movimiento,yGenerar)

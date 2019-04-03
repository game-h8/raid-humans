#include "../include/player.h"

using namespace sf;
using namespace std;


#define kVmax 300
player::player(string imgDirectory,float x2, float y2)
{


    if (!pTexture.loadFromFile(imgDirectory))
    {
        cerr << "Error cargando la imagen" << imgDirectory << endl;
        exit(0);

    }


    pSprite.setTexture(pTexture);
    pSprite.setOrigin(75/2,75/2);
    pSprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));


    x=x2;
    y=y2;



    pSprite.setPosition(x,y);
}

player::~player()
{
    //dtor
}


Vector2f player::movePlayer(Vector2f v , float time){
 //std::cout << "p--> x:"<< pos.x <<" y:"<< pos.y <<std::endl;
 // std::cout << "v--> x:"<< vel.x <<" y:"<< vel.y <<std::endl;
   // std::cout << "T--> "<< time <<" seg" <<std::endl;

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

void player:: render(float ticks, RenderWindow &ventana){

pSprite.setPosition(xlast*(1-ticks) + x*ticks,ylast*(1-ticks)+y*ticks);
ventana.draw(pSprite);
}




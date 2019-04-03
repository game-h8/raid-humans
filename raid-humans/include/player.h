#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;



class player
{
    public:

        player();
        player(string imgDirectory, float x, float y);
        virtual ~player();

        RectangleShape hitbox;
        Texture   pTexture;
        Sprite    pSprite;
        float     x;
        float     y;
        float     xlast;
        float     ylast;
        Vector2f   vel;





    Vector2f movePlayer(Vector2f a, float time);
    void render(float ticks, RenderWindow& ventana);


    protected:
    private:




};



#endif // PLAYER_H


#include "Moneda.h"
#include <iostream>

Moneda::Moneda(float x, float y, int valor)
{
    if(!mTex.loadFromFile("resources/CoinSheet.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
    mSprite.setTexture(mTex);
    mSprite.setOrigin(mSprite.getGlobalBounds().width/2,mSprite.getGlobalBounds().height/2);

    //Max 3000coins  min 100
    if(valor<=100){ // 1Moneda
        mSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    }
    else if(valor<=300){ // 2 Monedas
        mSprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
    }
    else if(valor<=500){ //Monton pequenio
        mSprite.setTextureRect(sf::IntRect(16*2, 0, 16, 16));
    }
    else if(valor<=1000){ //Monton grande
        mSprite.setTextureRect(sf::IntRect(16*3, 0, 16, 16));
    }
    else if(valor<=2000){ //Monton enorme
        mSprite.setTextureRect(sf::IntRect(0, 16, 16, 16));
    }
    else{ //Lingotes
        mSprite.setTextureRect(sf::IntRect(16*2, 16, 16, 16));
    }

    mSprite.setPosition(x,y);

    hitbox.setSize(sf::Vector2f(mSprite.getGlobalBounds().width*2, mSprite.getGlobalBounds().height*2));
    hitbox.setOrigin(mSprite.getGlobalBounds().width/2,mSprite.getGlobalBounds().height/2);
    hitbox.setPosition(sf::Vector2f(x,y));
}
void Moneda::movimiento(float x, float y){

}

void Moneda::render(sf::RenderWindow &Window){
    Window.draw(mSprite);
}

Moneda::~Moneda()
{
    //dtor
}

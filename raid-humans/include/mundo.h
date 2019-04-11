#ifndef MUNDO_H
#define MUNDO_H

#include <iostream>
#include <SFML/Graphics.hpp>

class mundo
{
    public:
        mundo();
        virtual ~mundo();

        static mundo* getMundo(); //Singleton

        void toggleDebug();
        bool getDebug();



        sf::Texture torretaTex;
        sf::Texture   eTexture;
        sf::Texture balaTex;


    protected:

    private:
        static mundo* _instancia;
        bool debug = false;

};

#endif // MUNDO_H

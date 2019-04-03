#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bala.h"
#include "Torreta.h"
#include <vector>

using namespace std;
int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
/*
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
*/
    //definir rectangulo, para selector
    sf::RectangleShape selector(sf::Vector2f(30.f, 30.f));
    sf::Color trasnparente(0, 0, 0, 1); //Cuadrado transparente
    selector.setFillColor(trasnparente);

    //Pintar borde del rectangulo, que sera e selector
    selector.setOutlineThickness(4.f);
    selector.setOutlineColor(sf::Color(255, 255, 255)); //Color blanco
    bool ponerTorreta=false;

    //Defino vector donde meto todas las balas
    std::vector<Bala> vectorBalas;

    //Defino vector donde iran las torretas
    std::vector<Torreta> vectorTorreta;


    bool disparando = false;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                ponerTorreta=true;
            }
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                disparando=true;
             }

            if(ponerTorreta ==true){
                //Obtener coordenadas de la ventana
                sf::Vector2i localPosition = sf::Mouse::getPosition(app);
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
                ponerTorreta = false;
             }


        //Dibujar selector en el mapa para poner la torreta donde marque

        //Obtener coordenadas de la ventana
        sf::Vector2i localPosition = sf::Mouse::getPosition(app);
        int posicionX = localPosition.x;
        int posicionY = localPosition.y;

        //Obtener parte entera de la division
        int i = (posicionX/32);
        int j = (posicionY/32);

        //Mostrar las coordenadas
        cout << "Mouse en posicion x: " << posicionX  <<"posicion y: " << posicionY << endl;
        //Mostrar las i  j
        cout << "i: " << i  <<"j: " << j << endl;

        //Dibujar el selector en el cuadrado de la matriz
        selector.setPosition(i*32.f ,j*32.f);

        }




        // Clear screen
        app.clear();

        // Draw the sprite
       // app.draw(sprite);
        //Recorrer el vector de torretas y dibujar las torretas
        for(int i=0; i<vectorTorreta.size(); i++)
            vectorTorreta[i].draw(app);

       app.draw(selector);
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

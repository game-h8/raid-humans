#include <SFML/Graphics.hpp>
#include "include/juego.h"
#include <player.h>
using namespace std;
using namespace sf;
int main()
{
    juego* game = new juego(Vector2u(1200,800));



    /*
    mapa mapa("resources/mapaprueba.tmx","resources/PathAndObjects.png");
    mapa.setActivateLayer(0);
    mapa.drawMapa(window);
    */

    /*
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

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
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);

        // Update the window
        app.display();
    }



    */
    return 0;
}


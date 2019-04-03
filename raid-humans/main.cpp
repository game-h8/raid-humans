#include <SFML/Graphics.hpp>
#include "include/juego.h"
#include "include/player.h"
#include "include/Bala.h"
#include "include/Torreta.h"
#include <vector>
using namespace std;
using namespace sf;
int main()
{
    juego* game = new juego(Vector2u(800,600));


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


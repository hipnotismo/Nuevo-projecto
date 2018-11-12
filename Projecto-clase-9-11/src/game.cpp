#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"
#include <ctime>

#include "game.h"


namespace Game
{
	void core()
	{
		sf::RenderWindow window(sf::VideoMode(700, 300), "STP Example");
		tmx::TileMap map("res/Mapa.tmx");

		sf::Texture t1, t2, t3;
		
		while (window.isOpen()) {
			// Process events
			sf::Event event;
			while (window.pollEvent(event)) {
				// Close window : exit
				if (event.type == sf::Event::Closed)
					window.close();
			}
			// Clear screen
			window.clear();
			// Draw the map
			window.draw(map);
			// Update the window
			window.display();
		}

	}
}
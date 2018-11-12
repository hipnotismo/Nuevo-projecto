#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"
#include <ctime>

#include "game.h"

struct Plat1
{
	int x = 200;
	int y = 155;
};
namespace Game
{
	void core()
	{
		sf::RenderWindow window(sf::VideoMode(700, 300), "STP Example");
		window.setFramerateLimit(60);

		tmx::TileMap map("res/Mapa.tmx");

		sf::Texture t1;

		t1.loadFromFile("res/Character.png");
		
		sf::Sprite Char(t1);

		int x = 100, y = 100, h = 200;
		float dx = 0, dy = 0;

		while (window.isOpen()) {
			// Process events
			sf::Event event;
			while (window.pollEvent(event)) 
			{
				// Close window : exit
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += 3;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= 3;

			dy += 0.2;
			y += dy;
			if (y>155)  dy = 0;

			Char.setPosition(x, y);

			// Clear screen
			window.clear();
			// Draw the map
			window.draw(map);
			window.draw(Char);
			// Update the window
			window.display();
		}

	}
}
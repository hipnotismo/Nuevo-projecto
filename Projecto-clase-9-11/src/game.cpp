#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

#include "game.h"


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

		static int Init_Char_x = 100;
		static int Init_Char_y = 100;
		static int x = Init_Char_x, y = Init_Char_y, h = 200;
		static float dx = 0, dy = 0;

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) y -= 7;

			dy += 0.2;
			y += dy;

			if (x <= 285) 
			{
				if (y > 155)
				{
					dy = 0;
				}
			}

			if (x >= 285 && x <= 430)
			{
				if (y > 150)
				{
					x = Init_Char_x;
					y = Init_Char_y;
				}
			}

			if (x >= 431)
			{
				if (y > 155)
				{
					dy = 0;
				}
			}

			if (x >= 650)
			{
				x -= 3;
			}

			if (x <= 0)
			{
				x += 3;
			}

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
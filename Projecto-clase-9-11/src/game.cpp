#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

#include "game.h"
#include "player.h"

namespace Game
{

	
	void core()
	{
		sf::RenderWindow window(sf::VideoMode(700, 300), "STP Example");
		window.setFramerateLimit(60);

		// Se crean las plataformas
		sf::RectangleShape rectangle1(sf::Vector2f(288, 32));
		sf::RectangleShape rectangle2(sf::Vector2f(32, 32));

		// Posicion de las plataformas
		rectangle1.setPosition(0,192);

		// Volver a las plataformas transparentes
		rectangle1.setFillColor(sf::Color::Transparent);


		tmx::TileMap map("res/Mapa.tmx");
		Player player;
		while (window.isOpen()) 
		{
			// Process events
			sf::Event event;
			while (window.pollEvent(event))
			{
				// Close window : exit
				if (event.type == sf::Event::Closed)
					window.close();

			}

			if (player.Char.getGlobalBounds().intersects(rectangle1.getGlobalBounds()))
			{
				player.dy = 0;
			}

			// dibujar jugador
			player.Movimiento();
			// Clear screen
			window.clear();
			// Draw the map
			window.draw(map);
			window.draw(player.Char);
			// Dibujar plataformas
			window.draw(rectangle1);
			window.draw(rectangle2);

			// Update the window
			window.display();
		}

	}

	void draw()
	{

	}
}
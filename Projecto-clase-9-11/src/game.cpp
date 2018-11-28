#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

#include "game.h"
#include "player.h"

namespace Game
{

	
	void core()
	{
		int Count = 0;
		//La ventana ocupa 22 bloques en "x" y 10 en "y"
		sf::RenderWindow window(sf::VideoMode(704, 320), "El dorito que salta");
		sf::View view(sf::Vector2f(576.0f, 480.0f), sf::Vector2f(704.0f,320.0f));

		window.setFramerateLimit(60);

		// Se crean las plataformas
		sf::RectangleShape rectangle1(sf::Vector2f(288, 32));
		sf::RectangleShape rectangle2(sf::Vector2f(32, 32));

		// Posicion de las plataformas
		rectangle1.setPosition(512,512);

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
			//Mobimiento de view
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				view.move(sf::Vector2f(3, 0));
				Count += 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				view.move(sf::Vector2f(-3, 0));
				Count -= 1;
				if (Count < 0)
				{
					view.move(sf::Vector2f(3, 0));
					Count = 0;
				}
			}
			if (player.Char.getGlobalBounds().intersects(rectangle1.getGlobalBounds()))
			{
				player.dy = 0.0f;
			}

			// dibujar jugador
			player.Movement();
			// Clear screen
			window.clear();
			//Camara
			//view.setCenter(player.Get_position());
			window.setView(view);
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
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

#include "game.h"
#include "player.h"

namespace Game
{

	
	void core()
	{
		// Variables Enem
		bool Alive = true;
		bool Touch = true;
		int test = 1;
		int Enem_Init_x = 2432;
		int Enem_Init_y = 480;
		int Enem_x = Enem_Init_x;
		int Enem_y = Enem_Init_y;

		// Variables Sword
		int Init_Sword_x = 544;
		int Init_Sword_y = 480;
		int Sword_x = Init_Sword_x;
		int Sword_y = Init_Sword_y;
		
		// Variables View
		int Count = 0;

		//La ventana ocupa 22 bloques en "x" y 10 en "y"
		sf::RenderWindow window(sf::VideoMode(704, 352), "El dorito que salta");
		sf::View view(sf::Vector2f(576.0f, 480.0f), sf::Vector2f(704.0f,320.0f));

		window.setFramerateLimit(60);

		// Se crean las plataformas
		sf::RectangleShape rectangle1(sf::Vector2f(288, 32));
		sf::RectangleShape rectangle2(sf::Vector2f(32, -480));
		sf::RectangleShape rectangle3(sf::Vector2f(160, 32));
		sf::RectangleShape rectangle4(sf::Vector2f(640, 32));
		sf::RectangleShape rectangle5(sf::Vector2f(384, 32));
		sf::RectangleShape rectangle6(sf::Vector2f(672, 32));
		sf::RectangleShape rectangle7(sf::Vector2f(160, 32));
		sf::RectangleShape rectangle8(sf::Vector2f(128, 32));
		sf::RectangleShape rectangle9(sf::Vector2f(352, 32));
		sf::RectangleShape rectangle10(sf::Vector2f(32, -480));
		sf::RectangleShape rectangle11(sf::Vector2f(32, 32));
		sf::RectangleShape Sword(sf::Vector2f(20, 10));

		// Posicion de las plataformas
		rectangle1.setPosition(512,512);
		rectangle2.setPosition(512, 512);
		rectangle3.setPosition(800, 512);
		rectangle4.setPosition(960, 512);
		rectangle5.setPosition(1600, 512);
		rectangle6.setPosition(1984, 512);
		rectangle7.setPosition(1152, 416);
		rectangle8.setPosition(1408, 384);
		rectangle9.setPosition(1600, 352);
		rectangle10.setPosition(2592, 512);
		rectangle11.setPosition(1984, 480);

		//Posicion espadaa y color
		Sword.setPosition(Sword_x, Sword_y);
		Sword.setFillColor(sf::Color(100, 250, 50));

		// Volver a las plataformas transparentes
		// Comentar transparente para ver que rectangulo es cual 
		rectangle1.setFillColor(sf::Color::Transparent);
		rectangle2.setFillColor(sf::Color::Transparent);
		rectangle3.setFillColor(sf::Color::Transparent);
		rectangle4.setFillColor(sf::Color::Transparent);
		rectangle5.setFillColor(sf::Color::Transparent);
		rectangle6.setFillColor(sf::Color::Transparent);
		rectangle7.setFillColor(sf::Color::Transparent);
		rectangle8.setFillColor(sf::Color::Transparent);
		rectangle9.setFillColor(sf::Color::Transparent);
		rectangle10.setFillColor(sf::Color::Transparent);
		rectangle11.setFillColor(sf::Color::Transparent);

		//Texture enemigo
		sf::Texture t_Enem, t_Dead;
		sf::Sprite Enem; 
		t_Enem.loadFromFile("res/Enemi.png");
		t_Dead.loadFromFile("res/Enemi_Dead.png");
		Enem.setTexture(t_Enem); 
		Enem.setPosition(Enem_x, Enem_y);

		// Mapa
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
				
				// "Matar" enemigo
				if (Sword.getGlobalBounds().intersects(Enem.getGlobalBounds()))
				{
					Enem.setTexture(t_Dead);
					Alive = false;
				}
			}

			

			// Mobimiento de view
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				view.move(sf::Vector2f(3, 0));
				Count += 1;
				if (player.Char.getGlobalBounds().intersects(rectangle10.getGlobalBounds()))
				{
					view.move(sf::Vector2f(-3, 0));
					Count -= 1;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				view.move(sf::Vector2f(-3, 0));
				Count -= 1;
				if (player.Char.getGlobalBounds().intersects(rectangle2.getGlobalBounds()))
				{
					view.move(sf::Vector2f(3, 0));
					Count += 1;
				}
			}

			// Mobimiento Enem
			if (Alive)
			{
				if (Touch)
				{
					Enem.move(3,0);
				}
				else
				{
					Enem.move(-3,0);
				}
			}

			// Direccion de enem
			if (Enem.getGlobalBounds().intersects(rectangle10.getGlobalBounds()))
			{
				Touch = false;
			}

			if (Enem.getGlobalBounds().intersects(rectangle11.getGlobalBounds()))
			{
				Touch = true;
			}

			// Mobimiento Sword
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) Sword.move(3,0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) Sword.move(-3,0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) Sword.move(0,-3);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) Sword.move(0,3);


			if (player.Char.getGlobalBounds().intersects(rectangle3.getGlobalBounds()))
			{
				while (Count >=0)
				{
					view.move(sf::Vector2f(-3, 0));
					Count -= 1;
				}
				
			}

			if (player.Char.getGlobalBounds().intersects(rectangle5.getGlobalBounds()))
			{
				while (Count >= 0)
				{
					view.move(sf::Vector2f(-3, 0));
					Count -= 1;
				}
			}

			if (player.Char.getGlobalBounds().intersects(Enem.getGlobalBounds()))
			{
				while (Count >= 0)
				{
					view.move(sf::Vector2f(-3, 0));
					Count -= 1;
				}
			}
			

			//Chequo de coliciones
			if (player.Char.getGlobalBounds().intersects(rectangle1.getGlobalBounds()))
			{
				player.dy = 0.0f;
			}

			if (player.Char.getGlobalBounds().intersects(rectangle2.getGlobalBounds()))
			{
				player.x += 3;
			}

			if (player.Char.getGlobalBounds().intersects(rectangle3.getGlobalBounds()))
			{
				player.x = player.Init_Char_x;
				player.y = player.Init_Char_y;
				Sword.setPosition(Sword_x, Sword_y);

			}

			if (player.Char.getGlobalBounds().intersects(rectangle4.getGlobalBounds()))
			{
				player.dy = 0.0f;
			}

			if (player.Char.getGlobalBounds().intersects(rectangle5.getGlobalBounds()))
			{
				player.x = player.Init_Char_x;
				player.y = player.Init_Char_y;
				Sword.setPosition(Sword_x, Sword_y);
			}

			if (player.Char.getGlobalBounds().intersects(rectangle6.getGlobalBounds()))
			{
				player.dy = 0.0f;
			}

			if (player.Char.getGlobalBounds().intersects(rectangle7.getGlobalBounds()))
			{
				player.dy = 0.0f;
			}

			if (player.Char.getGlobalBounds().intersects(rectangle8.getGlobalBounds()))
			{
				player.dy = 0.0f;
			}

			if (player.Char.getGlobalBounds().intersects(rectangle9.getGlobalBounds()))
			{
				player.dy = 0.0f;
			}

			if (player.Char.getGlobalBounds().intersects(rectangle10.getGlobalBounds()))
			{
				player.x -= 3;
			}

			// Colicion enemigo
			if (player.Char.getGlobalBounds().intersects(Enem.getGlobalBounds()))
			{
				if (Alive)
				{
					player.x = player.Init_Char_x;
					player.y = player.Init_Char_y;
					Sword.setPosition(Sword_x, Sword_y);
				}
			}

			// Dibujar jugador
			player.Movement();

			// Clear screen
			window.clear();

			// Camara
			window.setView(view);

			// Dibujar mapa
			window.draw(map);

			// Dibujar player
			window.draw(player.Char);

			// Dibujar enem
			window.draw(Enem);

			// Dibujar plataformas
			window.draw(rectangle1);
			window.draw(rectangle2);
			window.draw(rectangle3);
			window.draw(rectangle4);
			window.draw(rectangle5);
			window.draw(rectangle6);
			window.draw(rectangle7);
			window.draw(rectangle8);
			window.draw(rectangle9);
			window.draw(rectangle10);
			window.draw(rectangle11);

			//Dibujar Sword
			window.draw(Sword);
			// Update the window
			window.display();
		}

	}

	void draw()
	{

	}
}
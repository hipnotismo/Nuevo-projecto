#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"

namespace Game {
	class Player
	{
	public:
		Player();
		~Player();
		void Movement();
		sf::Sprite Char;
		float dy;

	private:

		int Init_Char_x;
		int Init_Char_y;
		int x, y, h;
		float dx;
		void Cargar_Sprite();
		sf::Texture t1;
	};

}
#endif
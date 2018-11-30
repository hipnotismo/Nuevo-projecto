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
		int x, y, Init_Char_x, Init_Char_y;

	private:
		float dx;
		void Load_Sprite();
		sf::Texture t1;
	};

}
#endif
#include "SFML/Graphics.hpp"

#include "player.h"

using namespace Game;

Player::Player()
{
	Init_Char_x = 576;
	Init_Char_y = 480;
	x = Init_Char_x;
	y = Init_Char_y;
	dx = 0;
	dy = 0;
	Load_Sprite();

}

Player::~Player()
{
}
void Player::Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) x += 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) x -= 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) y -= 7;
	dy += 0.2;
	y += dy;
	Char.setPosition(x, y);

}

void Player::Load_Sprite()
{
	t1.loadFromFile("res/Character.png");
	Char.setTexture(t1);
}

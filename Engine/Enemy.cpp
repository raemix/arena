#include "Enemy.h"

void Enemy::Init()
{
	width = 20;
	height = 25;
	x = (float)getRandomNumber(0, Graphics::ScreenWidth - width);
	y = (float)getRandomNumber(0, Graphics::ScreenHeight - height);
	speed = 3;
	red = 255;
	green = 0;
	blue = 0;




	isAlive = true;

}

void Enemy::Update(Player& player)
{

}

void Enemy::Die()
{
	isAlive = false;
}


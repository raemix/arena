#include "Enemy.h"

void Enemy::Init()
{
	width = 20;
	height = 25;
	setX((float)getRandomNumber(0, Graphics::ScreenWidth - width));
	setY((float)getRandomNumber(0, Graphics::ScreenHeight - height));
	speed = 3;
	red = 255;
	green = 0;
	blue = 0;




	isAlive = true;

}

void Enemy::Update(Player& player)
{
	targetLocationX = player.getLocation().x;
	targetLocationY = player.getLocation().y;

	moveTo(targetLocationX, targetLocationY);
	setLocation(Vec2(getLocation().x + getVX(),getLocation().y + getVY()));
}

void Enemy::Die()
{
	isAlive = false;
	setX(-50.0f);
	setY(-50.0f);
}


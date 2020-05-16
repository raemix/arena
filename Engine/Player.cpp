#include "Player.h"

void Player::Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H)
{
	x = X;
	y = Y;
	red = R;
	green = G;
	blue = B;
	speed = SPEED;
	width = W;
	height = H;
}

void Player::Update(const Mouse& mouse)
{
	moveToMouseLeft(mouse);
	// Stop if at target location
	if (abs((int)x - targetLocationX) <= targetPadding)
	{

		vx = 0.0f;
	}

	if (abs((int)y - targetLocationY) <= targetPadding)
	{
		vy = 0.0f;
	}
	if (abs((int)x - targetLocationX) <= targetPadding && abs((int)y - targetLocationY) <= targetPadding)
	{
		x = targetLocationX;
		y = targetLocationY;
	}

	// Move player based on above info
	if (vx > speed)
		vx = speed;
	if (vy > speed)
		vy = speed;
	x += vx;
	y += vy;
	if (x <= 0.0f)
	{
		x = 0.0f;
	}
	if (x + width >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - width;
	}
	if (y <= 0.0f)
	{
		y = 0.0f;
	}
	if (y + height >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height;
	}
}



Player::Player()
{
	Init(300.0f, 300.0f, 25, 255, 25, 5, 15, 20);
}


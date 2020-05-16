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

void Player::Update(const Keyboard& kbd)
{
	// Stop if at target location
	


	if (kbd.KeyIsPressed('W')) vy = -speed;
	if (kbd.KeyIsPressed('S')) vy = speed;
	if (kbd.KeyIsPressed('A')) vx = -speed;
	if (kbd.KeyIsPressed('D')) vx = speed;

	if (!kbd.KeyIsPressed('W') && !kbd.KeyIsPressed('S')) vy = 0;
	if (!kbd.KeyIsPressed('A') && !kbd.KeyIsPressed('D')) vx = 0;


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


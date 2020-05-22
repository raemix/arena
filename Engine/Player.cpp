#include "Player.h"

void Player::Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H)
{
	setX(X);
	setY(Y);
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
	setX(getLocation().x + vx);
	setY(getLocation().y + vy);
	if (getLocation().x <= 0.0f)
	{
		setX(0.0f);
	}
	if (getLocation().x + width >= Graphics::ScreenWidth)
	{
		setX(Graphics::ScreenWidth - width);
	}
	if (getLocation().y <= 0.0f)
	{
		setY(0.0f);
	}
	if (getLocation().y + height >= Graphics::ScreenHeight)
	{
		setY(Graphics::ScreenHeight - height);
	}
}



Player::Player()
{
	Init(300.0f, 300.0f, 25, 255, 25, 5, 15, 20);
}


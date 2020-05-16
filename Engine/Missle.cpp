#include "Missle.h"

Missle::Missle(float X, float Y, int R, int G, int B, int SPEED, int W, int H, const Mouse& mouse)
{
	Init( X,  Y,  R,  G,  B,  SPEED,  W,  H, mouse);
}

void Missle::Destroy()
{
	delete this;
}

void Missle::Update(const Keyboard& kbd, const Mouse& mouse)
{
	// Stop if at target location
	if (abs((int)x - (int)targetLocationX) <= targetPadding)
	{

		vx = 0.0f;
	}

	if (abs((int)y - (int)targetLocationY) <= targetPadding)
	{
		vy = 0.0f;
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
		Destroy();
	}
	if (x + width >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - width;
		Destroy();
	}
	if (y <= 0.0f)
	{
		y = 0.0f;
		Destroy();
	}
	if (y + height >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height;
		Destroy();
	}
}



void Missle::Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H, const Mouse& mouse)
{
	x = X;
	y = Y;
	red = R;
	green = G;
	blue = B;
	speed = SPEED;
	width = W;
	height = H;
	moveToMouseRight(mouse);

}

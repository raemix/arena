#include "Missle.h"

Missle::Missle()
{
	
}

void Missle::Destroy()
{
	active = false;

}

void Missle::Update()
{
	
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



void Missle::Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H, int targetX, int targetY)
{
	x = X;
	y = Y;
	red = R;
	green = G;
	blue = B;
	speed = SPEED;
	width = W;
	height = H;
	targetLocationX = targetX;
	targetLocationY = targetY;
	active = true;
	moveTo(targetLocationX, targetLocationY);

}

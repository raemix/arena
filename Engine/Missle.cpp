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
	if (getVX() > speed)
		setVX(speed);
	if (getVY() > speed)
		setVY(speed);
	setX(getLocation().x + getVX());
	setY(getLocation().y + getVY());
	if (getLocation().x <= 0.0f - width)
	{
		//x = 0.0f;
		Destroy();
	}
	if (getLocation().x + width >= Graphics::ScreenWidth)
	{
		//x = Graphics::ScreenWidth - width;
		Destroy();
	}
	if (getLocation().y <= 0.0f)
	{
		//y = 0.0f;
		Destroy();
	}
	if (getLocation().y + height >= Graphics::ScreenHeight)
	{
		//y = Graphics::ScreenHeight - height;
		Destroy();
	}
}



void Missle::Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H, int targetX, int targetY)
{
	setX(X);
	setY(Y);
	red = R;
	green = G;
	blue = B;
	speed = SPEED;
	width = W;
	height = H;
	targetLocationX = (float)targetX;
	targetLocationY = (float)targetY;
	active = true;
	moveTo(targetLocationX, targetLocationY);

}

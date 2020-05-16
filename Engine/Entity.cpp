#include "Entity.h"

void Entity::Draw(float X, float Y, Graphics& gfx)
{
	int x = (int)X;
	int y = (int)Y;

	for (int y_loop = 0; y_loop < height; y_loop++)
	{
		for (int x_loop = 0; x_loop < width; x_loop++)
		{
			gfx.PutPixel(x + x_loop, y + y_loop, red, green, blue);

		}
	}
}

//void Entity::Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H)
//{
//	x = X;
//	y = Y;
//	r = R;
//	g = G;
//	b = B;
//	speed = SPEED;
//	width = W;
//	height = H;
//}

void Entity::moveToMouseLeft(const Mouse& mouse)
{
	if (mouse.LeftIsPressed())
	{
		// Determine destination
		targetLocationX = mouse.GetPosX();
		targetLocationY = mouse.GetPosY();
		moveX = (float)targetLocationX - x;
		moveY = (float)targetLocationY - y;

		// Calculate velocities
		slope = sqrt((moveX * moveX) + (moveY * moveY));
		vx = moveX / slope * speed;
		vy = moveY / slope * speed;
	}

	
}

void Entity::moveToMouseRight(const Mouse& mouse)
{
	if (mouse.RightIsPressed())
	{
		// Determine destination
		targetLocationX = mouse.GetPosX();
		targetLocationY = mouse.GetPosY();
		moveX = (float)targetLocationX - x;
		moveY = (float)targetLocationY - y;

		// Calculate velocities
		slope = sqrt((moveX * moveX) + (moveY * moveY));
		vx = moveX / slope * speed;
		vy = moveY / slope * speed;
	}

	
}

//void Entity::Update()
//{	
//}



float Entity::getX()
{
	return x;
}

float Entity::getY()
{
	return y;
}

void Entity::setX(float X)
{
	x = X;
}

void Entity::setY(float Y)
{
	y = Y;
}

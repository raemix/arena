#include "Entity.h"

void Entity::Draw(Graphics& gfx)
{
	Draw(loc.x, loc.y, gfx);
}

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


void Entity::moveTo(float X, float Y)
{
	// Determine destination
	targetLocationX = (int)X;
	targetLocationY = (int)Y;
	moveX = (float)targetLocationX - getLocation().x;
	moveY = (float)targetLocationY - getLocation().y;

	// Calculate velocities
	slope = sqrt((moveX * moveX) + (moveY * moveY));
	setVX(moveX / slope * speed);
	setVY(moveY / slope * speed);
}

bool Entity::isColliding(Entity& e)
{
	return 
		getLocation().x + width >= e.getLocation().x &&
		getLocation().x <= e.getLocation().x + e.width &&
		getLocation().y + height >= e.getLocation().y &&
		getLocation().y <= e.getLocation().y + e.height;
}

void Entity::moveToMouseRight(const Mouse& mouse)
{
	if (mouse.RightIsPressed())
	{
		// Determine destination
		moveTo(mouse.GetPosX(), mouse.GetPosY());
		
	}
}

void Entity::moveToMouseLeft(const Mouse& mouse)
{
	if (mouse.LeftIsPressed()) moveTo(mouse.GetPosX(), mouse.GetPosY());
}

//void Entity::Update()
//{	
//}



Vec2 Entity::getLocation()
{
	return loc;
}

void Entity::setLocation(float in_x, float in_y)
{
	loc.x = in_x;
	loc.y = in_y;
}

void Entity::setLocation(Vec2& location)
{
	loc.x = location.x;
	loc.y = location.y;
}

Vec2 Entity::getVelocity()
{
	return Vec2(getVX(), getVY());
}

//float Entity::getX()
//{
//	return loc.x;
//}
//
//float Entity::getY()
//{
//	return loc.y;
//}

float Entity::getVX()
{
	return vel.x;
}

float Entity::getVY()
{
	return vel.y;
}

void Entity::setVX(float in_vx)
{
	vel.x = in_vx;
}

void Entity::setVY(float in_vy)
{
	vel.y = in_vy;
}

void Entity::setX(float X)
{
	loc.x = X;
}

void Entity::setY(float Y)
{
	loc.y = Y;
}

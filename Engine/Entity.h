#pragma once

#include "Graphics.h"
#include "Mouse.h"
#include "Keyboard.h"
#include <ctgmath>

class Entity
{
public:
	float x = 0.0f;
	float y = 0.0f;
	int width = 15;
	int height = 20;
	int targetLocationX = 0;
	int targetLocationY = 0;
	float vx = 0.0f;
	float vy = 0.0f;
	float slope = 0.0f;
	float moveX = 0.0f;
	float moveY = 0.0f;
	float xySquared = 0.0f;
	float xySqareRoot = 0.0f;
	int red   = 255;
	int green = 255;
	int blue  = 255;
	int speed = 1;
	int targetPadding = 2;



private:
	//void Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H);


public:
	float getX();
	float getY();
	void setX(float X);
	void setY(float Y);
	//void Update();
	void Draw(float X, float Y, Graphics& gfx);
	void moveToMouseRight(const Mouse& mouse);
	void moveToMouseLeft(const Mouse& mouse);
	void moveTo(float X, float Y);
};
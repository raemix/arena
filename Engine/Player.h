#pragma once

#include "Graphics.h"
#include "Mouse.h"
#include "Keyboard.h"
#include <ctgmath>
#include "Entity.h"


class Player : public Entity
{
	
	

public:



private:
	void Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H);


public:
	Player();
	void Update(const Keyboard& kbd);

};
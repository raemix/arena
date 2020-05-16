#pragma once
#include "Entity.h"



class Missle : public Entity
{
private:


public:
	bool active = false;

private:
	void Destroy();
public:
	Missle();
	void Update();
	void Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H, int targetX, int targetY);

};
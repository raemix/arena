#pragma once
#include "Entity.h"



class Missle : public Entity
{
private:


public:


private:
	void Init(float X, float Y, int R, int G, int B, int SPEED, int W, int H, const Mouse& mouse);
	void Destroy();
public:
	Missle(float X, float Y, int R, int G, int B, int SPEED, int W, int H, const Mouse& mouse);
	void Update(const Keyboard& kbd, const Mouse& mouse);

};
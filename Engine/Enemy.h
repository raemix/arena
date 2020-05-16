#pragma once

#include "Entity.h"
#include "Player.h"




class Enemy : public Entity
{

public:
	bool isAlive = false;
	int spawnChance = 100;
	void Init();
	void Update(Player& player);
	void Die();
};
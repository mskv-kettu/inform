#pragma once

#include "Player.h"

class Wizard : public Player
{
public:
	Wizard(int maxHealth, int health, int intellect, int strength);
	virtual ~Wizard();

	int getDamage() override;
};
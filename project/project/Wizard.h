#pragma once

#include "Player.h"

class Wizard : public Player
{
public:
	Wizard();
	~Wizard();

	int getDamage() override;
	bool canUse(Item* item) override;
};
#pragma once
#include "Item.h"
#include "Player.h"

class Consumables : Item
{
public:
	Consumables(string title, int weight);
	Consumables() {};

	virtual ~Consumables() {};
	// silly warnings and mistakes! Must get Player* type;
	virtual bool apply(void* object) = 0;

};


#pragma once
#include "Item.h"

class Potion : public Item
{
protected:
	int health;
public:
	// may be changed and extended
	Potion(string title, int weight, int health);
	Potion() {};
	~Potion() {};

	int getEffect();
};


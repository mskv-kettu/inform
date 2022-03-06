#pragma once
#include "Consumables.h"

class Potion : public Consumables
{
protected:
	int effect;
public:
	// may be changed and extended
	Potion(string title, int weight, int effect);
	Potion() {};

	virtual ~Potion() {};

	int Effect();
	virtual bool apply(void* object) override;
};


#include "Potion.h"

Potion::Potion(string title, int weight, int effect) : Consumables(title, weight), effect(effect) {}

int Potion::Effect()
{
	return effect;
}

bool Potion::apply(void* object)
{
	Player* obj = (Player*)object;
	obj->Health(effect + obj->Health());
	return true;
}
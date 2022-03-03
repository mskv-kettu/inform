#include "Potion.h"

Potion::Potion(string title, int weight, int health) : Item(title, weight), health(health)
{

}

int Potion::getEffect()
{
	return health;
}
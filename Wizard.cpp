#include "Wizard.h"


Wizard::Wizard(int maxHealth, int health, int intellect, int strength) : Player( maxHealth, health, intellect, strength) {};
Wizard::~Wizard() {};

int Wizard::getDamage()
{
	return this->intellect;
}
#include "Monster.h"
#include <iostream>;

Monster::Monster(string Name, unsigned int level, int baseDamage)
{
	this->Name = Name;
	this->level = level;
	this->baseDamage = baseDamage;
}

Monster::~Monster() {};

string Monster::getName()
{
	return this->Name;
}
unsigned int Monster::getLevel()
{
	return this->level;
}
int Monster::getBaseDamage()
{
	return this->baseDamage;
}
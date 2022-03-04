#include "Monster.h"
#include <iostream>

Monster::Monster(string Name, unsigned int level, int baseDamage, int hp)
{
	this->Name = Name;
	this->level = level;
	this->baseDamage = baseDamage;
	this->CurrentHp = hp;
}
Monster::Monster() {};
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
int Monster::getCurrentHp() {
	return this->CurrentHp*(rand() % 3);
}
void Monster::getCurrentHp(int hp) {
	this->CurrentHp = hp;
}
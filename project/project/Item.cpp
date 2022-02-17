#include "Item.h"

Item::Item(string title, int weight, unsigned int level, bool magical, int baseDamage)
{
	this->title = title;
	this->weight = weight;
	this->level = level;
	this->magical = magical;
	this->baseDamage = baseDamage;
}

Item::~Item() {};

string Item::getTitle()
{
	return this->title;
}

int Item::getWeight()
{
	return this->weight;
}

unsigned int Item::getLevel()
{
	return this->level;
}

bool Item::isMagical()
{
	return this->magical;
}

int Item::getBaseDamage()
{
	return this->baseDamage;
}
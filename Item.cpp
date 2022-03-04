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


int Item::Damage()
{
	return this->baseDamage;
}
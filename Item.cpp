#include "Item.h"

Item::Item(string title, int weight)
{
	this->title = title;
	this->weight = weight;
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
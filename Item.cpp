#include "Item.h"

Item::Item(string title, int weight, string type)
{
	this->title = title;
	this->weight = weight;
}

Item::~Item() {};

string Item::Title()
{
	return title;
}

int Item::Weight()
{
	return weight;
}

string Item::Type()
{
	return type;
}
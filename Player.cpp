#include "Player.h"

// default inventory space is 3

Player::Player(int maxHealth, int health, int intellect, int strength) : inventory(3)
{
	this->maxHealth = maxHealth;
	this->health = health;
	this->intellect = intellect;
	this->strength = strength;
	itself = this;
}

Player::~Player() 
{
}

void Player::Strength(int strength)
{
	this->strength = strength;
}
int Player::Strength()
{
	return this->strength;
}


void Player::Intellect(int intellect)
{
	this->intellect = intellect;
}
int Player::Intellect()
{
	return this->intellect;
}

void Player::MaxHealth(int maxHealth)
{
	this->maxHealth = maxHealth;
}
int Player::MaxHealth()
{
	return this->maxHealth;
}

void Player::Health(int health)
{
	this->health = health;
}
int Player::Health()
{
	return this->health;
}


//Inventory

Player::Inventory::Inventory(unsigned int space)
{
	this->space = space;
	inventory = new Item*[space];
	for (unsigned int i = 0; i < space; i++)
	{
		 inventory[i] = NULL;
	}
}

Player::Inventory::~Inventory()
{
	delete[] inventory;	
	std::cout << "inventory cleared";
}

unsigned int Player::Inventory::GetTotalSpace()
{
	return space;
}

unsigned int Player::Inventory::GetAmountOfItems()
{
	unsigned int amountOfItems = 0;
	for (unsigned int i = 0; i < space; i++)
	{
		if (inventory[i] != NULL) amountOfItems++;
	}
	return amountOfItems;
}

void Player::Inventory::Sort()
{
	// 2 sorts
	// firstly exising ones
	unsigned int sortedPosition = 0;
	for (unsigned int i = 0; i < space; i++)
	{
		if (inventory[i] != NULL)
		{
			inventory[sortedPosition] = inventory[i];
			inventory[i] = NULL;
			sortedPosition++;
		}
	}

	// sort types of items
	// Im too lazy to think about it
	Item* temp;
	for (unsigned int i = 0; i < sortedPosition; i++)
	{
		for (unsigned int j = sortedPosition - 1; j > i; j--)
		{
			if (inventory[j]->Type() > inventory[j - 1]->Type())
			{
				temp = inventory[j];
				inventory[j] = inventory[j - 1];
				inventory[j - 1] = temp;
			}
		}
	}
}

bool Player::UseItem(Item* item)
{
	//DANGEROUS
	void* ITEM = item;
	if (item->Type() == "Consumables")
	{
		Consumables* consItem = (Consumables*)ITEM;

		// Make apply return false if failed

		consItem->apply(itself);
		item = NULL;
		return true;
	}
	return false;
}
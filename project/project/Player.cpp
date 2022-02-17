#include "Player.h";

Player::Player() {}

Player::~Player() {}

void Player::setStrength(int strength)
{
	this->strength = strength;
}
void Player::setLevel(int level)
{
	this->level = level;
}

int Player::getStrength()
{
	return this->strength;
}
unsigned int Player::getLevel()
{
	return this->level;
}

void Player::setIntellect(int intellect)
{
	this->intellect = intellect;
}
int Player::getIntellect()
{
	return this->intellect;
}

void Player::setMaxHealth(int maxHealth)
{
	this->maxHealth = maxHealth;
}
int Player::getMaxHealth()
{
	return this->maxHealth;
}

void Player::setHealth(int health)
{
	this->health = health;
}
int Player::getHealth()
{
	return this->health;
}

//virtual int Player::getDamage() = 0;

//virtual bool Player::canUse(Item* item);
#include "Player.h"

Player::Player(int maxHealth, int health, int intellect, int strength)
{
	this->maxHealth = maxHealth;
	this->health = health;
	this->intellect = intellect;
	this->strength = strength;
}

Player::~Player() {}

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
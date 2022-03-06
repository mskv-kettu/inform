#pragma once

#include "Item.h"
#include "Consumables.h"


class Player
{
// Inventory
    class Inventory
    {
    private:
        unsigned int space;
    public: // Temporary
        Item** inventory;
    public:

        Inventory(unsigned int space);
        ~Inventory();

        unsigned int GetTotalSpace();
        unsigned int GetAmountOfItems();
        void Sort();
    };

protected:
	int maxHealth;
    int health;
	int intellect;
    int strength;
    
    Player* itself;
    
public:
    Inventory inventory;

public:
    //constructor
    Player(int maxHealth, int health, int intellect, int strength);
    
    virtual ~Player() = 0;

    // Set absolute value of strength
    void Strength(int strength);
    // Get value of strength
    int Strength();

    // Set absolute value of intellect
    void Intellect(int intellect);
    // Get value of intellect
    int Intellect();

    // Set absolute value of maximum health
    void MaxHealth(int maxHealth);
    // Get value of maximum health
    int MaxHealth();

    // Set absolute value of current health
    void Health(int health);
    // Get value of current health
    int Health();

    // Damage function
    virtual int getDamage() = 0;

    bool UseItem(Item* item);
};
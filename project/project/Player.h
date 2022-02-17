#pragma once

#include "Item.h"

class Player
{
protected:
	unsigned int level;
	int maxHealth;
    int health;
	int intellect;
    int strength;

public:
    Player();
    
    virtual ~Player();

    // Задать силу
    void setStrength(int strength);
    // Задать уровень
    void setLevel(int level);

    // Получить силу
    int getStrength();
    // Получить уровень
    unsigned int getLevel();

    //
    void setIntellect(int intellect);
    //
    int getIntellect();

    //
    void setMaxHealth(int maxHealth);
    //
    int getMaxHealth();

    //
    void setHealth(int health);
    //
    int getHealth();

    virtual int getDamage();

    // Проверка, может ли игрок использовать предмет
    virtual bool canUse(Item* item);
};
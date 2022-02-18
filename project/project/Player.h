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

    // ������ ����
    void setStrength(int strength);
    // ������ �������
    void setLevel(int level);

    // �������� ����
    int getStrength();
    // �������� �������
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

    // ��������, ����� �� ����� ������������ �������
    virtual bool canUse(Item* item);
};
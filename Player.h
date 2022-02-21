#pragma once

class Player
{
protected:
	int maxHealth;
    int health;
	int intellect;
    int strength;

public:
    //constructor
    Player(int maxHealth, int health, int intellect, int strength);
    
    virtual ~Player() = 0;

    // ������ ����
    void Strength(int strength);
    // �������� ����
    int Strength();

    //
    void Intellect(int intellect);
    int Intellect();

    //
    void MaxHealth(int maxHealth);
    int MaxHealth();

    // Health get/set
    void Health(int health);
    int Health();

    virtual int getDamage() = 0;
};
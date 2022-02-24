#pragma once

#include <iostream>

using std::string;

class Monster {
protected:
    string Name;
    unsigned int level;
    int baseDamage;
    int CurrentHp;
public:
    Monster(string Name, unsigned int level, int baseDamage, int hp);
    Monster();

    virtual ~Monster();

    string getName();

    unsigned int getLevel();

    int getBaseDamage();

    int getCurrentHp();

    void changeHp(int hp);
};
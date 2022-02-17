#pragma once

#include <iostream>

using std::string;

class Monster {
protected:
    string Name;
    unsigned int level;
    int baseDamage;
public:
    Monster(string Name, unsigned int level, int baseDamage);

    virtual ~Monster();

    string getName();
    // Получить уровень Монстра
    unsigned int getLevel();
    // Получить базовый урон
    int getBaseDamage();
};

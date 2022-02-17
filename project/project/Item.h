#pragma once

#include <iostream>

using std::string;

class Item {
protected:
    string title;
    int weight;
    unsigned int level;
    bool magical;
    int baseDamage;
public:
    Item(string title, int weight, unsigned int level, bool magical, int baseDamage);

    virtual ~Item();

    string getTitle();
    // Получить вес предмета
    int getWeight();
    // Получить уровень предмета
    unsigned int getLevel();
    // Получить, является ли предмет магичным
    bool isMagical();
    // Получить базовый урон
    int getBaseDamage();
};

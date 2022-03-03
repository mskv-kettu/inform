#pragma once

#include <iostream>

using std::string;

class Item {
protected:
    string title;
    int weight;
    int baseDamage;
public:
    Item(string title, int weight);
    Item() {};

    virtual ~Item();

    string getTitle();
    // Получить вес предмета
    int getWeight();
    // Получить базовый урон
};

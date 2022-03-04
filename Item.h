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

    int getWeight();

    unsigned int getLevel();

    bool isMagical();

    int getBaseDamage();
};

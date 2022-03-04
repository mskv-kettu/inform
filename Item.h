#pragma once

#include <iostream>

using std::string;

class Item {
protected:
    string title;
    int weight;
    unsigned int level;
    int Damage;
public:
    Item(string title, int weight, unsigned int level, int Damage);

    virtual ~Item();

    string getTitle();

    int getWeight();

    unsigned int getLevel();


    int Damage();
};

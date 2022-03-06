#pragma once

#include <iostream>

using std::string;

// make it virtual

class Item {
protected:
    string title;
    int weight;
    const string type;
public:
    Item(string title, int weight, string type);
    Item() {};

    virtual ~Item();

    string Title();
    int Weight();
    string Type();
};

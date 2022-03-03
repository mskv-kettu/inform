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
    // �������� ��� ��������
    int getWeight();
    // �������� ������� ����
};

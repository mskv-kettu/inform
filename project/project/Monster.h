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
    // �������� ������� �������
    unsigned int getLevel();
    // �������� ������� ����
    int getBaseDamage();
};

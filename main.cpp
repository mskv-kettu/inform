#include <iostream>
#include "Event.h"
#include "FightEvent.h"
#include "Monster.h"
#include "Wizard.h"

using namespace std;

int main()
{
    Wizard* wiz = new Wizard(10, 10, 10, 0);

    Monster* monsterPack[10];
    for (int i = 0; i < 10; i++)
    {
        monsterPack[i] = new Monster("Ghost", 1, 2, 30);
    }


    for (int i = 0; i < 10; i++)
    {
        FightEvent fight1(wiz, monsterPack[i]);
        fight1.fightEventHandler();
    }
    
    delete wiz;
    for (int i = 0; i < 10; i++)
    {
        delete monsterPack[i];
    }
    delete[] monsterPack;
    return 0;
}
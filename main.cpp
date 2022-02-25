#include <iostream>
#include "Event.h"
#include "FightEvent.h"
#include "Monster.h"
#include "Wizard.h"
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main()
{
    Wizard* wiz = new Wizard(10, 10, 10, 0);

    Monster* monsterPack[10];
    for (int i = 0; i < 10; i++)
    {
       int typesMonster=rand() % 3;
       switch(typesMonster){
           case 0:
               monsterPack[i] = new Monster("Ghost", 1, 2, 30);
               break;
           case 1:
               monsterPack[i] = new Monster("Zombie", 1, 1, 35);
               break;
           case 2:
               monsterPack[i] = new Monster("Bandit", 1, 10, 1);
    }}


    for (int i = 0; i < 10; i++)
    {
        FightEvent fight1(wiz, monsterPack[i]);
        fight1.fightEventHandler();
    }
    
    delete wiz;
    for (int i = 0; i < 10; i++) {
        delete monsterPack[i];
    }
    return 0;
}
#include <iostream>
#include "Event.h"
#include "Monster.h"
#include "Wizard.h"

using namespace std;

int main()
{
    Wizard* wiz = new Wizard(10, 10, 10, 0);
    Monster* monster = new Monster("Ghost", 1, 2, 30);
    
    while (wiz->Health() > 0 and monster->getCurrentHp())
    {
        monster->changeHp(monster->getCurrentHp() - wiz->getDamage());
        if (monster->getCurrentHp() <= 0) break;
        wiz->Health(wiz->Health() - monster->getBaseDamage());
        cout << "\nwizard hp: " << wiz->Health() << "\n" << "monster hp: " << monster->getCurrentHp() << "\n";
    }

    cout << "\nwizard hp: " << wiz->Health() << "\n" << "monster hp: " << monster->getCurrentHp() << "\n";

    delete wiz;
    delete monster;
    return 0;
}
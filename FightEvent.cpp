#include <FightEvent.h>
#include <windows.h>

FightEvent::FightEvent(Player* player, Monster* monster)
{
	this->id = 1;

	this->player = player;
	this->monster = monster;
	std::cout << "\n\n----------------	It`s " << monster->getName() << " in front of you	----------------\n\n";
}

FightEvent::~FightEvent() {};

// It`s impossible to activate method from constructor
void FightEvent::fightEventHandler()
{
	
	while (player->Health() > 0 and monster->getCurrentHp())
	{
		std::cout << "\nYour HP: " << player->Health() << "\n";
		std::cout << monster->getName() << " HP: " << monster->getCurrentHp() << "\n";
		if (playerTurn())
		{
			std::cout << "\nYou retreated\n";
            return;
		}
		if (monster->getCurrentHp() <= 0) break;
		opponentTurn();
	}
	if (player->Health() == 0)
	{
		std::cout << "\nYou are DEAD\n";
	}
	if (monster->getCurrentHp() == 0)
	{
		std::cout << "\nYou WON\n";
	}
}

bool FightEvent::playerTurn()
{
	std::cout << "\n\n=======	It`s your turn	=======\n";
	
	unsigned int action;
	do {
		std::cout << "\nPossible actions:\n";
		std::cout << "1 - to attack\n";
		std::cout << "2 - to retreat\n";
		std::cout << "You choose: ";
		std::cin >> action;
	} while (action > 2);
	
	int dmg;
    int Randomattc=rand()%3;
	switch (action)
	{
	case (1):

		dmg = player->getDamage()*Randomattc;
		monster->changeHp(monster->getCurrentHp() - dmg);
        switch (Randomattc){
            case (0):
                std::cout << "\nMISS\n";
                break;
            case (1):
                std::cout << "\nYour dmg: " << dmg << "\n";
                break;
            case (2):
		        std::cout << "\nCRITICAL DAMAGE\nYour dmg: " << dmg << "\n";
                }
        return false;
	case (2):
		return true;
	}
}

void FightEvent::opponentTurn()
{
	std::cout << "\n\n=======	It`s opponent`s turn	=======\n";

	// 
	unsigned int action = 1;
	int dmg;
	switch (action)
	{
	case 1:
		dmg = monster->getBaseDamage()*(rand() % 3);
		player->Health(player->Health() - dmg);
		std::cout << "\nYou took: " << dmg << "\n";
		break;
	}
}
#include "FightEvent.h"

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
	
	int action;
	do {
		std::cout << "\nPossible actions:\n";
		std::cout << "1 - to attack\n";
		std::cout << "2 - to use inventory\n";
		std::cout << "3 - to retreat\n";
		std::cout << "You choose: ";
		std::cin >> action;


		int dmg;
		unsigned int N;
		switch (action)
		{
		case 1:
			dmg = player->getDamage();
			monster->changeHp(monster->getCurrentHp() - dmg);
			std::cout << "\nYour dmg: " << dmg << "\n";
			return false;
		case 2:
			// May be relocated
			N = player->inventory.GetAmountOfItems();
			do {
				std::cout << "\nYour inventory:\n";
				
				for (unsigned int i = 0; i < N; i++)
				{
					std::cout << i << " - " << player->inventory.inventory[i]->Title() << "\n";
				}
				std::cout << N << " - to return";
				std::cin >> action;
			} while ((action < 1 || action > N) && action != N);

			// Leaving
			if (action == N)
			{
				action = 0;
				break;
			}
			// Choosing item
			else
			{
				player->UseItem(player->inventory.inventory[action]);
			}
			return true;
		case 3:
			return true;
		}
	} while (action > 3 || action < 1);
	return false;
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
		dmg = monster->getBaseDamage();
		player->Health(player->Health() - dmg);
		std::cout << "\nYou took: " << dmg << "\n";
		break;
	}
}


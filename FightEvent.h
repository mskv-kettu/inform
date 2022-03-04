#pragma once

#include "Event.h"
#include "Monster.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include "Item.h"


class FightEvent : public Event
{
public:
	FightEvent(Player* player, Monster* monster);
	virtual ~FightEvent();

	Player* player;
	Monster* monster;

	void fightEventHandler();
	bool playerTurn();
	void opponentTurn();
};


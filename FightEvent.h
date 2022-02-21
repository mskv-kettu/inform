#pragma once

#include "Event.h"

class FightEvent : public Event
{
public:
	FightEvent() {};
	~FightEvent() {};
	void playerTurn();
	void opponentTurn();
};


#pragma once
#include "Strategy.h"
#include "Map.h"
#include "Deck.h"

class Agressive : public Strategy {
public:
	void RollDice();
	void ResolveDice();
	void move(Map &map);
	void buyCards(Deck &deck);
};


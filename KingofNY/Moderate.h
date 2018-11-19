#pragma once
#include "Strategy.h"
#include "Map.h"
#include "Deck.h"

class Moderate : public Strategy {
public:
	Moderate();
	~Moderate();

	void RollDice();
	void ResolveDice();
	void move(Map &map);
	void buyCards(Deck &deck);
};

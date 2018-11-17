#pragma once
#include "Strategy.h"
#include "../Map.h"
#include "../Deck.h"
#include "../Dice.h"

class Human : public Strategy {

public:
	Human();
	~Human();
	//from strategy
	void RollDice();
	void ResolveDice();
	void move(Map &map);
	void buyCards(Deck &deck);
};

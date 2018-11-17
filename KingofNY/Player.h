#pragma once
#include "Dice.h"
#include "Monster.h"
#include "Card.h"
#include "Token.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include "Deck.h"
#include"Card.h"
#include "Map.h"
#include "Strategies/Strategy.h"

class Player
{
private:
	Strategy *strategy;
	string playerName;

public:
	Player();
	~Player();
	Player(string);
	Player(Strategy *initStrategy);
	void setStrategy(Strategy *newStrategy);

	//Strategy specific
	void executeRollDice();
	void executeResolveDice();
	void executeMove(Map &map);
	void executeBuyCards(Deck &deck);

	string getName();
};


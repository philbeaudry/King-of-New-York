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
#include "Strategy.h"


class Player
{
private:
	Strategy *strategy;

public:
	Player();
	~Player();
	Player(Strategy *initStrategy, string name);
	void setStrategy(Strategy *newStrategy);

	//Strategy specific
	void executeRollDice();
	void executeResolveDice();
	void executeMove(Map &map);
	void executeBuyCards(Deck &deck);

	//calls the strategy class, but are defined in the stragegy since they are the same no matter the type
	string getName();
	Dice getDice();
	void startRoll();
	void chooseRegion(Map &map);
	Node getRegion();
	vector<string> getValues();
	void chooseMonster(Deck &deck);
	Monster getMonster();
};


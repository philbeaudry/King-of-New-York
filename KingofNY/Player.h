#pragma once
#include "Dice.h"
#include "Monster.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
class Player
{
public:
	Player();
	Player(string);
	~Player();
	string getName();
	void RollDice();
	void ResolveDice();
	void Move();
	Dice dice;
	vector <string> getDiceValues();
	void resolveValue(string,int);
	void solveEnergy(int);
	void solveAttack(int);
	void solveDestruction(int);
	void solveHeal(int);
	void solveCelebrity(int);
	void solveOuch(int);

private:
	string playerName;
	int energyCount;
	vector <string> diceValues;
	vector <string> tokens;
	vector <string> cards;
	Monster monsterCard;
	//vector <Token> tokens;
	//vector <Region> regions;
};


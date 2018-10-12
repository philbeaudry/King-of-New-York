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
#include"Card.h"

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
	vector <Card> getCards();
	Monster getMonster();
	vector <Token> getTokens();
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
	vector <Card> cards;
	Monster monsterCard;
	vector <Token> tokens;
	//vector <Region> regions;
};


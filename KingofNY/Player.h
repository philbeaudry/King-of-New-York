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

	string playerName;
	int energyCount;
	bool superstar;
	vector <Card> cards;
	vector <Token> tokens;
	Node region;
	Dice dice;

public:
	Player();
	Player(Strategy *initStrategy);
	void setStrategy(Strategy *newStrategy);

	int executeStrategy();
	//Strategy specific
	void RollDice();
	void ResolveDice();
	void move(Map &map);
	void buyCards(Deck &deck);

	Player(string);
	~Player();
	Monster monsterCard;
	Dice getDice();
	string getName();
	int getEnergy();
	bool hasSuperstar();
	void setSuperStar(string change);
	vector <string> getDiceValues();
	vector <string> getValues();
	void startRoll();
	vector <Card> getCards();
	Monster getMonster();
	Node getRegion();
	//for demo purposes
	vector<Token> getTokens();
	void resolveValue(string,int);
	void solveEnergy(int);
	void solveAttack(int);
	void solveDestruction(int);
	void solveHeal(int);
	void solveCelebrity(int);
	void solveOuch(int);

	void chooseMonster(Deck deck);
	void chooseRegion(Map &map);

	void addToken(Token token);
	void buyCard(Deck &deck, Card card, int i);
	void buyDiscard(Deck &deck);
	void discardCards(Deck &deck);
};


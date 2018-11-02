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

class Player
{
private:
	string playerName;
	int energyCount;
	bool superstar;
	vector <string> diceValues;
	vector <Card> cards;
	vector <Token> tokens;
	Node region;
	//vector <Region> regions;

public:
	Monster monsterCard;
	Player();
	Player(string);
	~Player();
	string getName();
	int getEnergy();
	bool hasSuperstar();
	void setSuperStar(string change);
	void RollDice();
	void ResolveDice();
	void Move();
	Dice dice;
	vector <string> getDiceValues();
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
	void chooseRegion(Map map);

	void addToken(Token token);
	void move(Map map);
	void buyCards(Deck deck);
	void buyCard(Card Card);
	void buyDiscard(Deck deck);
	void discardCards(Deck deck);
};


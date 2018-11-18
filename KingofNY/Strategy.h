#pragma once
#include <vector>
#include "Map.h"
#include "Deck.h"
#include "Dice.h"

class Strategy {

protected:
	int energyCount;
	bool superstar;
	string playerName;
	vector <Card> cards;
	vector <Token> tokens;
	Node region;
	Dice dice;
	Monster monsterCard;
public:
	//Strategy will change with the types of players
	virtual void RollDice();
	virtual void ResolveDice();
	virtual void move(Map &map);
	virtual void buyCards(Deck &deck);

	//These are used with all the strategies
	Dice getDice();
	int getEnergy();
	bool hasSuperstar();
	void setSuperStar(string change);
	vector <string> getDiceValues();
	vector <string> getValues();
	void startRoll();
	vector <Card> getCards();
	Node getRegion();
	Monster getMonster();
	string getName();
	void setName(string name);

	void resolveValue(string, int);
	void solveEnergy(int);
	void solveAttack(int);
	void solveDestruction(int);
	void solveHeal(int);
	void solveCelebrity(int);
	void solveOuch(int);

	//for demo purposes
	vector<Token> getTokens();
	void chooseMonster(Deck &deck);
	void chooseRegion(Map &map);
	void addToken(Token token);
	void buyCard(Deck &deck, Card card, int i);
	void buyDiscard(Deck &deck);
	void discardCards(Deck &deck);
};




#pragma once
#include <vector>
#include "../Map.h"
#include "../Deck.h"
#include "../Dice.h"

class Strategy {

private:
	string playerName;
	int energyCount;
	bool superstar;
	vector <Card> cards;
	vector <Token> tokens;
	Node region;
	Dice dice;
public:
	virtual void RollDice();
	virtual void ResolveDice();
	virtual void move(Map &map);
	virtual void buyCards(Deck &deck);

	//for code behevior
	void resolveValue(string, int);
	void solveEnergy(int);
	void solveAttack(int);
	void solveDestruction(int);
	void solveHeal(int);
	void solveCelebrity(int);
	void solveOuch(int);

	Monster getMonster();
};




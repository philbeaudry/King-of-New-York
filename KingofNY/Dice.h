#pragma once
#include <string>
#include <array>
#include <vector>

using namespace std;
class Dice
{
public:
	Dice();
	vector <string> valueArray;
	string numToValue(int);
	void firstRoll();
	void rollDie(int[],int);
	void rerollDie();
	void displayDiceValues();
	void rerollAll();
	//void resetDice();
	void diceDriver();
	vector <string> getDiceValues();
};


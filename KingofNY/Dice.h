#pragma once
#include <string>
#include <array>

using namespace std;
class Dice
{
public:
	string valueArray[6];
	int rollNumber;
	Dice();
	string numToValue(int);
	void firstRoll();
	void rollSingleDice(int);
	void rollMultipleDie(int, int);
	void resetDice();
	void diceDriver();
	
};


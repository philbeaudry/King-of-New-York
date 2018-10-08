// KingofNY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Dice.h"
#include <iostream>
#include "Player.h"
using namespace std;

int main()
{
	//Dice dice1;
	//dice1.diceDriver();
	Player p1;
	p1.diceValues.diceDriver();

	cout << endl;
	cout << "displaying test";

	vector <string> test = p1.diceValues.getDiceValues();

	for (unsigned int i = 0; i < test.size(); i++) {
		cout << test[i] << endl;
	}
	
}
	


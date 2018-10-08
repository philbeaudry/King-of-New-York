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
	Player p1 = Player("John");
	
	p1.RollDice();
	vector <string> test = p1.getDiceValues();

	p1.ResolveDice();
	
}
	


// KingofNY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Dice.h"
#include <iostream>
#include "Player.h"
#include "Deck.h"
using namespace std;

int main()
{
	//Dice dice1;
	//dice1.diceDriver();
	/*Player p1 = Player("John");
	
	p1.RollDice();
	p1.ResolveDice();
	*/
	Deck deck = Deck();
	deck.generateDeck();

	vector <Card> test = deck.getDeck();

	for (unsigned int i = 0; i < test.size(); i++) {
		string name = test[i].getName();
		cout << name << endl;
	}

	deck.shuffleDeck();
	test = deck.getDeck();
	cout << "==============================";

	for (unsigned int i = 0; i < test.size(); i++) {
		string name = test[i].getName();
		cout << name << endl;
	}

}
	


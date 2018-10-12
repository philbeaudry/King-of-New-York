#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>


using namespace std;
class Dice
{
	public:
		Dice();
		Dice(string);
		vector<string> valueArray;
		vector<string> keepArray;
		string numToValue(int);
		void firstRoll();
		void rollDie(int[],int);
		void rerollDie();
		void displayDiceValues();
		void displayKeptValues();
		void rerollAll();
		void keepDice();
		//void resetDice();
		void diceDriver();
		vector <string> getDiceValues();
		bool isFull();

	private:
		string owner;

};


#include "pch.h"
#include "Dice.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>


using namespace std;

Dice::Dice()
{
}

void Dice::displayDiceValues() {
	for (int i = 0; i < 6; i++) {
		cout << "Dice #" << i + 1 << ": " << valueArray[i] << endl;
		cout << endl;
	}
};

string Dice::numToValue(int num) {
	int result = num;
	string value = "";
	switch (result)
	{
	case 1:
		value = "Energy";
		break;
	case 2: 
		value = "Attack";
		break;
	case 3: 
		value = "Destruction";
		break;
	case 4: 
		value = "Heal";
		break;
	case 5: 
		value = "Celebrity";
		break;
	case 6: 
		value = "Ouch!";
		break;
	}
	return value;
}

void Dice::firstRoll() {
	srand(time(NULL));
	for (int i = 0; i < 6 ; i++) {
		int random = (rand() % 6) + 1;
		valueArray[i] = numToValue(random);
		cout << endl;
		cout << "Dice #" << i +1 << ": " << valueArray[i] << endl;
	}
}

void Dice:: rollDie(int diceNumber[], int arraySize) {
	srand(time(NULL));
	for (int i = 0; i < arraySize; i++) {
		cout << "rerolling dice #" << diceNumber[i] << endl;
		int random = (rand() % 6) + 1;
		valueArray[diceNumber[i]] = numToValue(random);
	}
	cout << "new dice values are:" << endl;
	displayDiceValues();

};

void Dice::rerollDie() {
	int numOfDices = 0 ;
	int diceSelection;
	int rerollArray[6];

	cout << "how many die would you like to reroll (1-6)?" << endl;
	cin >> numOfDices;
	if (numOfDices == 6) {
		firstRoll();
	}
	else if (numOfDices >= 1 && numOfDices <= 5) {
		for (int i = 0; i < numOfDices; i++) {
			cout << "enter a dice position you would like to reroll" << endl;
			cin >> diceSelection;
			if (diceSelection < 1 || diceSelection > 6) {
				cout << "Invalid intput, exiting ";
			}
			rerollArray[i] = diceSelection;
			diceSelection = 0;
		}
		rollDie(rerollArray,numOfDices);
	}
	else {
		cout << "Invalid intput, exiting ";
	}
}

void Dice::diceDriver() {
	int numOfDices;
	int numOfRolls = 1;
	string answer;
	int diceSelection;
	int rerollArray[6];

	cout << "1st Roll: rolling dice...";
	firstRoll();
	while(numOfRolls < 4){
		cout << "Would you like to roll again?";
		cin >> answer;

		if (answer == "yes" || answer == "Yes") {
			rerollDie();
			numOfRolls++;
		}
		else if (answer == "no" || answer == "No") {
			cout << "OK! retaining previous roll";
			break;
		}
		else {
			cout << "Invalid answer, retaining previous roll.";
			break;
		}
	}
}


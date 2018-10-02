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
		cout << "Dice #" << i << ": " << valueArray[i] << endl;
	}
}

void Dice:: rollSingleDice(int diceNumber) {
	valueArray[diceNumber] = "Ouch";
};

void Dice::rollMultipleDie(int, int) {

}

void Dice::diceDriver() {
	int numOfDices;
	int numOfRolls;

	cout << "1st Roll: rolling dice...";
	firstRoll();
	

	/*cout << "How many dices do you wish to roll? (1-6)";
	cin >> numOfDices;*/


}


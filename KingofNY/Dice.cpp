#include "pch.h"
#include "Dice.h"

using namespace std;

Dice::Dice(){
	owner = "";
}

Dice::Dice(string playerName) {
	owner = playerName;
}

vector <string> Dice::getDiceValues() {
	return keepArray;
}

//Displays current dice values onto screen
void Dice::displayDiceValues() {
	for (int i = 0; i < valueArray.size(); i++) {
		cout << "Dice #" << i + 1 << ": " << valueArray[i] << endl;
		cout << endl;
	}
};

void Dice::displayKeptValues() {
	for (int i = 0; i < keepArray.size(); i++) {
		cout << "Dice #" << i + 1 << ": " << keepArray[i] << endl;
		cout << endl;
	}
};

//converts numerical value of dice to corresponding value
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

//method to reroll all die
void Dice::rerollAll() {
	srand(time(NULL));
	for (int i = 0; i < 6; i++) {
		int random = (rand() % 6) + 1;
		valueArray[i] = numToValue(random);
	}
	displayDiceValues();
}
//initial roll of the dice
void Dice::firstRoll() {
	srand(time(NULL));
	for (int i = 0; i < 6 ; i++) {
		int random = (rand() % 6) + 1;
		valueArray.push_back(numToValue(random));
		cout << endl;
		cout << "Dice #" << i +1 << ": " << valueArray[i] << endl;
	}
}

//method to roll specific dies
void Dice:: rollDie(int diceNumber[], int arraySize) {
	srand(time(NULL));
	for (int i = 0; i < arraySize; i++) {
		cout << "rerolling dice #" << diceNumber[i] << endl;
		int random = (rand() % 6) + 1;
		valueArray[diceNumber[i] - 1] = numToValue(random);
	}
	cout << "new dice values are:" << endl;
	displayDiceValues();

};

//method that handles dice rerolling
void Dice::rerollDie() {
	int numOfDices = 0 ;
	int diceSelection;
	int rerollArray[6];

	cout << "how many die would you like to reroll (1-6)?" << endl;
	cin >> numOfDices;
	while (numOfDices < 1 || numOfDices > 6)
	{
		cout << "Invalid Input, must be between 1 and 6" << endl;
		cin >> numOfDices;
	}
	if (numOfDices == 6) {
		rerollAll();
	}
	else {
		for (int i = 0; i < numOfDices; i++) {
			cout << "Enter a dice position you would like to reroll: " << endl;
			cin >> diceSelection;
			while (diceSelection < 1 || diceSelection > 6)
			{
				cout << "Invalid Input, must be between 1 and 6" << endl;
				cin >> diceSelection;
			}
			rerollArray[i] = diceSelection;
			diceSelection = 0;
		}
		rollDie(rerollArray,numOfDices);
	}
}

bool Dice::isFull() {
	if (this->keepArray.size() == 6) {
		return true;
	}
	else {
		return false;
	}
}

void Dice::keepDice() {
	int keepNumber;
	int keepSelection;
	cout << "How many of these die would you like to keep?";
	int space = 6 - keepArray.size();
	cin >> keepNumber;
	while (keepNumber > space || keepNumber < 0)
	{
		cout << "Invalid Input, you have a maximum of "<< space << " dice to left to keep: "<< endl;
		cin >> keepNumber;
	}
	if (keepNumber == 6) {
		for (int i = 0; i < 6; i++) {
			this->keepArray.push_back(valueArray[i]);
		}
	}
	else{
		for (int i = 0; i < keepNumber; i++) {
			cout << "Enter a dice position you would like to keep: ";
			cin >> keepSelection;
			while (keepSelection < 1 || keepSelection > 6)
			{
				cout << "Invalid Input, must be between 1 and 6, please try again." << endl;
				cin >> keepSelection;
			}
			this->keepArray.push_back(valueArray[keepSelection - 1]);
		}
	}
}

//method for dice rolling up to 3 times
void Dice::diceDriver() {
	int numOfDices;
	int numOfRolls = 1;
	string answer;
	int diceSelection;
	int rerollArray[6];

	cout << "1st Roll: rolling dice...";
	firstRoll();
	keepDice();
	displayDiceValues();
	
	while(numOfRolls < 3){
		if (keepArray.size() < 6) {
			cout << "Would you like to roll again (yes, no)?";
			cin >> answer;
			while (answer != "yes" && answer != "no" && answer != "Yes" && answer != "No") {
				cout << "Invalid answer. Please enter yes or no: ";
				cin >> answer;
			}
			if (answer == "yes" || answer == "Yes") {
				rerollDie();
				numOfRolls++;
				keepDice();
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
		else {
			cout << "You have kept the maximum amount of dice for this turn!" << endl;
			break;
		}
	}
}


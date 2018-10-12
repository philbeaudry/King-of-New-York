#include "pch.h"
#include "Player.h"


//default constructor
Player::Player(){
	playerName = "";
}

//constructor
Player::Player(string name) {
	playerName = name;
}

//returns player name
string Player::getName() {
	return playerName;
}

//destructor
Player::~Player()
{
}

//method called by player object to commence dice roll sequence
void Player::RollDice() {
	return dice.diceDriver();

}

//returns dice values for player for current turn
vector <string> Player::getDiceValues() {
	return dice.getDiceValues();
}

//returns player cards
vector<Card> Player::getCards()
{
	return cards;
}

//returns player Monster
Monster Player::getMonster()
{
	return monsterCard;
}

//returns player tokens
vector<Token> Player::getTokens()
{
	return tokens;
}

//method that calls various method to handle dice resolution phase
void Player::resolveValue(string type, int count) {
	if (type == "Energy") {
		solveEnergy(count);
	}
	else if (type == "Attack") {
		solveAttack(count);
	}
	else if (type == "Destruction") {
		solveDestruction(count);
	}
	else if (type == "Heal") {
		solveHeal(count);
	}
	else if (type == "Celebrity") {
		solveCelebrity(count);
	}
	else if (type == "Ouch!") {
		solveOuch(count);
	}
}

//increments player's energy count
void Player::solveEnergy(int count)
{
	this->energyCount = this->energyCount + count;
}

//resolves attack effect
void Player::solveAttack(int count)
{
}

//resolves destruction effect
void Player::solveDestruction(int count)
{
}

//resolves heal effect
void Player::solveHeal(int count)
{
}

//resolves celebrity effect
void Player::solveCelebrity(int count)
{
}

//resolves ouch effect
void Player::solveOuch(int count)
{
}

//method that prompts the player for order of dice to be resolved
void Player::ResolveDice() {
	int resolveChoice;
	vector <int> resolveOrder;
	vector<string> values = dice.getDiceValues();
	map<string, int> valueCount;
	map<int, string> options;
	int enCount = 0;
	int atCount = 0;
	int deCount = 0;
	int heCount = 0;
	int ceCount = 0;
	int ouCount = 0;

	for (int i = 0; i < values.size(); i++) {
		if (values[i] == "Energy") {
			enCount++;
		}
		else if (values[i] == "Attack") {
			atCount++;
		}
		else if (values[i] == "Destruction") {
			deCount++;
		}
		else if (values[i] == "Heal") {
			heCount++;
		}
		else if (values[i] == "Celebrity") {
			ceCount++;
		}
		else if (values[i] == "Ouch!") {
			ouCount++;
		}
	}
	valueCount["Energy"] = enCount;
	valueCount["Attack"] = atCount;
	valueCount["Destruction"] = deCount;
	valueCount["Heal"] = heCount;
	valueCount["Celebrity"] = ceCount;
	valueCount["Ouch!"] = ouCount;


	sort(values.begin(), values.end());
	
	auto iter = unique(values.begin(), values.end());
	values.erase(iter, values.end());
	
	cout << "Select the order in which you would like to resolve your die.";
	for (int i = 0; i < values.size(); i++) {
		options[i + 1] = values[i];
		cout << endl;
		cout << "Option #" << i + 1 << ": " << values[i] << endl;
	}
	for (int i = 1; i <= values.size(); i++) {
		cout << "Enter dice option number:";
		cin >> resolveChoice;
		while (resolveChoice < 1 || resolveChoice > 6)
		{
			cout << "Invalid Input, must be between 1 and 6, please try again." << endl;
			cin >> resolveChoice;
		}
		resolveOrder.push_back(resolveChoice);
	}
	for (int i = 0; i < resolveOrder.size(); i++) {
		resolveValue(options[resolveOrder[i]],valueCount[options[resolveOrder[i]]]);
	}

	

}

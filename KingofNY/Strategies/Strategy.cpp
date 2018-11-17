#include "../pch.h"
#include "Strategy.h"

void Strategy::RollDice() {};

void Strategy::ResolveDice() {};

void Strategy::move(Map &map) {}

void Strategy::buyCards(Deck &deck) {};

Dice Strategy::getDice() {
	return this->dice;
}

int Strategy::getEnergy()
{
	return this->energyCount;
}

bool Strategy::hasSuperstar()
{
	return superstar;
}

void Strategy::setSuperStar(string change)
{
	if (change == "truse") {
		this->superstar = true;
	}
	else if (change == "false") {
		this->superstar = false;
	}
}

//returns dice values for player for current turn
vector<string> Strategy::getDiceValues() {
	return dice.getDiceValues();
}


vector <string> Strategy::getValues() {
	return dice.getValues();
}

void Strategy::startRoll() {
	return dice.startRoll();
}

//returns player cards
vector<Card> Strategy::getCards() {
	return cards;
}

//returns player Monster
Monster Strategy::getMonster() {
	return monsterCard;
}

//returns player tokens
vector<Token> Strategy::getTokens()
{
	return tokens;
}

Node Strategy::getRegion() {
	return region;
}

void Strategy::chooseMonster(Deck deck) {
	vector<Monster> monsters = deck.getMonsters();

	cout << "Choose one of the Monsters from the following options: " << endl;

	int i = 1;
	for (Monster monster : monsters) {
		cout << i << " :" << monster.getName() << endl;
		i++;
	}

	int monsterChoice;

	cin >> monsterChoice;

	while (monsterChoice > monsters.size() || monsterChoice < 0) {
		cout << "Please choose valid monster from the list: " << endl;
		cin >> monsterChoice;
	}

	this->monsterCard = monsters[monsterChoice - 1];

	cout << "You have choosen to play has: " << this->monsterCard.getName() << endl;
}


//method that calls various method to handle dice resolution phase
void Strategy::resolveValue(string type, int count) {
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
void Strategy::solveEnergy(int count)
{
	this->energyCount += count;
}

//resolves attack effect
void Strategy::solveAttack(int count)
{
}

//resolves destruction effect
void Strategy::solveDestruction(int count)
{
}

//resolves heal effect
void Strategy::solveHeal(int count)
{
	int HP = this->getMonster().getlifePoints();
	if (HP >= 10) {
		cout << "Your monster has already the maximum amount of health points!" << endl;
	}
	else {
		this->monsterCard.modifyLifePoints("increase", count);
		int HP2 = this->getMonster().getlifePoints();
		cout << "Your monster now has " << HP2 << " health points!" << endl;
	}
}

//resolves celebrity effect
void Strategy::solveCelebrity(int count)
{
	int surplus = count - 3;

	if (this->hasSuperstar() == true) {
		this->monsterCard.modifyVictoryPoints("increase", surplus);
	}
	else if (count < 3) {
		cout << "You have rolled less than 3 Celebrity dice, nothing happens!";
	}
	else if (count >= 3) {
		if (this->hasSuperstar() == false) {
			this->setSuperStar("true");
			this->monsterCard.modifyVictoryPoints("increase", surplus);
		}
	}
}

//resolves ouch effect
void Strategy::solveOuch(int count)
{
}

//method that prompts the player for order of dice to be resolved
void Strategy::ResolveDice() {
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
		while (resolveChoice > options.size() || resolveChoice < 0)
		{
			cout << "Invalid Input, must in option list, please try again." << endl;
			cin >> resolveChoice;
		}
		resolveOrder.push_back(resolveChoice);
	}
	for (int i = 0; i < resolveOrder.size(); i++) {
		resolveValue(options[resolveOrder[i]], valueCount[options[resolveOrder[i]]]);
	}
}

void Strategy::chooseRegion(Map &map) {

	vector<Node> regions = map.graph.getRegions();

	cout << this->playerName << ": Choose the id of the Region you would like to start at: " << endl;

	int i = 0;
	for (Node region : regions) {
		if (region.start != false && map.graph.getNbOfPlayersInZone(region.id) < 2) {
			cout << region.id << " :" << region.name << endl;
		}
		i++;
	}

	int regionChoice;

	cin >> regionChoice;

	Node region = map.graph.getNodeFromId(regionChoice);

	while (region.start == false || map.graph.getNbOfPlayersInZone(region.id) >= 2) {
		cout << "Please choose valid region Id from the list: " << endl;
		cin >> regionChoice;
		region = map.graph.getNodeFromId(regionChoice);
	}

	cout << "You have choosen to start: " << region.name << endl;

	this->region = region;

	//add to the player count of the ZONE
	int currentSize = map.graph.getNbOfPlayersInZone(regionChoice);
	map.graph.setNbOfPlayersInZone(regionChoice, ++currentSize);
}

void Strategy::addToken(Token token) {
	this->tokens.push_back(token);
}

void Strategy::buyCard(Deck &deck, Card card, int i) {
	if (this->getEnergy() - card.getCost() < 0) {
		cout << "You do not have enough energy to buy this card!";
	}
	else {
		this->energyCount -= card.getCost();
		deck.removeCard(i);
		deck.drawCard();
		this->cards.push_back(card);
	}
}

void Strategy::buyDiscard(Deck &deck)
{
	int buyDisc;
	int cardSelect;

	for (int i = 0; i < deck.availCards.size(); i++) {
		cout << "Card " << i + 1 << ":" << deck.availCards[i].getName() << endl;
	}
	cout << "Would you like to buy a card or discard available cards?" << endl;
	cout << "Press 1 to buy or Press 2 to discard" << endl;
	cin >> buyDisc;
	while (buyDisc != 1 && buyDisc != 2) {
		cout << "Invalid answer. Please enter 1 or 2: ";
		cin >> buyDisc;
	}
	if (buyDisc == 1) {
		cout << "Which card would you like to buy?";
		cin >> cardSelect;
		while (cardSelect < 1 || cardSelect > 3)
		{
			cout << "Invalid Input, must be between 1 and 3, please try again." << endl;
			cin >> cardSelect;
		}
		buyCard(deck, deck.availCards[cardSelect - 1], cardSelect - 1);
	}
	else if (buyDisc == 2) {
		cout << "OK! Replacing available cards with 3 new ones." << endl;
		discardCards(deck);
	}
}

void Strategy::discardCards(Deck &deck)
{
	if (this->getEnergy() < 2) {
		cout << "You do not have enough energy to discard cards!" << endl;
	}
	else if (this->getEnergy() >= 2) {
		for (int i = 0; i < 3; i++) {
			deck.removeTop();
		}
		for (int i = 0; i < 3; i++) {
			deck.drawCard();
		}
		cout << "Here are the new cards that are available" << endl;
		for (int i = 0; i < deck.availCards.size(); i++) {
			cout << "Card " << i + 1 << ":" << deck.availCards[i].getName() << endl;
		}
	}
	this->energyCount -= 2;
}



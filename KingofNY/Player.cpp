#include "pch.h"
#include "Player.h"


Dice Player::getDice() {
	return this->dice;
}

//default constructor
Player::Player() {
	playerName = "";
	energyCount = 50;
}

Player::Player(Strategy * initStrategy) {
	this->strategy = initStrategy;
}

void Player::setStrategy(Strategy * newStrategy) {
	this->strategy = newStrategy;
}

void Player::executeRollDice() {
	this->strategy->RollDice();
}

void Player::executeResolveDice() {
	this->strategy->ResolveDice();
}

void Player::executeMove(Map & map) {
	this->strategy->move(map);
}

void Player::executeBuyCards(Deck & deck) {
	this->strategy->buyCards(deck);
}

//constructor
Player::Player(string name) {
	playerName = name;
	energyCount = 50;
	superstar = false;
}

//returns player name
string Player::getName() {
	return playerName;
}

int Player::getEnergy()
{
	return this->energyCount;
}

bool Player::hasSuperstar()
{
	return superstar;
}

void Player::setSuperStar(string change)
{
	if (change == "truse") {
		this->superstar = true;
	}
	else if (change == "false") {
		this->superstar = false;
	}
}

//destructor
Player::~Player(){
}

//returns dice values for player for current turn
vector <string> Player::getDiceValues() {
	return dice.getDiceValues();
}


vector <string> Player::getValues() {
	return dice.getValues();
}

void Player::startRoll() {
	return dice.startRoll();
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

Node Player::getRegion() {
	return region;
}

void Player::chooseMonster(Deck deck) {
	vector<Monster> monsters = deck.getMonsters();

	cout << "Choose one of the Monsters from the following options: " << endl;

	int i = 1;
	for(Monster monster : monsters) {
		cout << i << " :" << monster.getName() << endl;
		i++;
	}

	int monsterChoice;

	cin >> monsterChoice;

	while (monsterChoice > monsters.size() || monsterChoice < 0){
		cout << "Please choose valid monster from the list: " << endl;
		cin >> monsterChoice;
	}

	this->monsterCard = monsters[monsterChoice - 1];

	cout << "You have choosen to play has: " << this->monsterCard.getName() << endl;
}

void Player::chooseRegion(Map &map) {

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

void Player::addToken(Token token) {
	this->tokens.push_back(token);
}

void Player::buyCard(Deck &deck, Card card,int i) {
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

void Player::buyDiscard(Deck &deck)
{
	int buyDisc;
	int cardSelect;
	
	for (int i = 0; i < deck.availCards.size(); i++) {
		cout << "Card " << i + 1 << ":" << deck.availCards[i].getName() << endl;
	}
	cout << "Would you like to buy a card or discard available cards?" << endl;
	cout << "Press 1 to buy or Press 2 to discard" << endl;
	cin >> buyDisc;
	while (buyDisc != 1  &&  buyDisc != 2) {
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

void Player::discardCards(Deck &deck)
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
			cout << "Card " << i + 1<< ":" << deck.availCards[i].getName() << endl;
		}
	}
	this->energyCount -= 2;
}



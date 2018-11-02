#include "pch.h"
#include "Player.h"


//default constructor
Player::Player(){
	playerName = "";
}

//constructor
Player::Player(string name) {
	playerName = name;
	energyCount = 0;
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

Node Player::getRegion() {
	return region;
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
	this->energyCount += count;
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
	int HP = this->getMonster().getlifePoints();
	if (HP >= 10) {
		cout << "Your monster has already the maximum amount of health points!";
	}
	else {
		this->monsterCard.modifyLifePoints("increase",count);
		int HP2 = this->getMonster().getlifePoints();
		cout << "Your monster now has " << HP2 << " health points!";
	}
}

//resolves celebrity effect
void Player::solveCelebrity(int count)
{
	int surplus = count - 3;

	if (this->hasSuperstar() == true) {
			this->monsterCard.modifyVictoryPoints("increase", surplus);
	}
	else if (count < 3) {
		cout << "You have rolled less than 3 Celebrity dice, nothing happens!";
	}
	else if (count >= 3){
		if (this->hasSuperstar() == false) {
			this->setSuperStar("true");
				this->monsterCard.modifyVictoryPoints("increase", surplus);
		}
	}
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

void Player::chooseRegion(Map map) {

	vector<Node> regions = map.graph.getRegions();

	cout << "Choose the id of the Region you would like to start at: " << endl;

	int i = 0;
	for (Node region : regions) {
		if (region.start != false) {
			cout << region.id << " :" << region.name << endl;
		}
		i++;
	}

	int regionChoice;

	cin >> regionChoice;

	Node region = map.graph.getNodeFromId(regionChoice);

	while (region.start == false) {
		cout << "Please choose valid region Id from the list: " << endl;
		cin >> regionChoice;
		region = map.graph.getNodeFromId(regionChoice);
	}

	region.nbPlayers++;

	cout << "You have choosen to start: " << region.name << endl;

	this->region = region;
}

void Player::addToken(Token token) {
	this->tokens.push_back(token);
}

void Player::move(Map map) {
	vector<Node> positions = map.graph.availableRegions(this->region.id);

	cout << "Please Choose the zone you would like to move too from these" << endl;
	int i = 0;
	for (Node node : positions) {
		cout << i << ": "<< node.name << endl;
		i++;
	}

	if (positions.size() == 1) {
		cout << "You need to move to Manhattan" << endl;
		this->region = positions[0];
	}
	else {
		int playerChoice;
		cin >> playerChoice;
		while (playerChoice < positions.size() || playerChoice > positions.size()) {
			cout << "enter valied region ID" << endl;
			cin >> playerChoice;
		}
		this->region = positions[playerChoice];
	}
}


bool Player::buyCard(Card card) {
	if (this->energyCount - card.getCost() <= 0) {
		return false;
	}

	this->energyCount = -card.getCost();
	this->cards.push_back(card);
	return true;
}



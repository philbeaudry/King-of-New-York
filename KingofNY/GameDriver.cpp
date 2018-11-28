#include "pch.h"
#include "GameDriver.h"
#include "DiceObserver.h"
#include <vector>

using namespace std;

GameDriver::GameDriver(){
}

GameDriver::~GameDriver() {
}


bool GameDriver::selectMap(string file) {
	this->gameMap = Map(file);

	if (gameMap.CreateMap()) {
		cout << "Map has been succesfuly loaded" << endl;
		return true;
	}
	else {
		cout << "Problem: Map not loaded succesfully" << endl;
		return false;
	}
	return false;
}

Map GameDriver::getMap() {
	return this->gameMap;
}

bool GameDriver::loadPlayers() {
	cout << "How many players will be playing the game today?" << endl;
	int nbPlayers;
	cin >> nbPlayers;

	while (nbPlayers < 2 || nbPlayers > 6) {
		cout << "Enter number of players between 2 and 6" << endl;
		cin >> nbPlayers;
	}

	this->nbPlayers = nbPlayers;
	this->playerArray.resize(nbPlayers);

	Deck deck;
	deck.generateDeck();
	deck.generateMonsters();
	for (int i = 0; i < nbPlayers; i++) {
		cout << "Player " << i << ", what NAME would you like to use?" << endl;
		string playerName = string();
		cin >> playerName;
    
		cout << playerName << ", is what type of player?(human, agressive or moderate)" << endl;

		string playerType;
		cin >> playerType;
		while (playerType != "human" && playerType != "agressive" && playerType != "moderate") {
			cout << playerName << ", choose one of the following type (human, agressive or moderate)" << endl;
			cin >> playerType;
		}

		Player player;
		if (playerType == "human") {
			player = Player(new Human(), playerName);
		}
		else if (playerType == "agressive") {
			player = Player(new Agressive(), playerName);
		}
		else if (playerType == "moderate") {
			player = Player(new Moderate(), playerName);
		}
	
		player.chooseMonster(deck);
		this->playerArray[i] = player;
	}
	return true;
}

void GameDriver::printPlayers() {
	cout << "List of players:" << endl;
	for (int i = 0; i < nbPlayers; i++)
		cout << playerArray[i].getName() << endl;
}

void GameDriver::startup() {
	for (Player &player : orderedPlayerArray) {
		player.chooseRegion(this->gameMap);
	}
}

void GameDriver::determineOrder() {
	map<string, int> order;
	//6 black dice and the 2 green dice	
	int nbAttack = 0;
	for (int i = 0; i < this->playerArray.size(); i++) {
		nbAttack = 0;
		cout << endl;
		cout << "Rolling for " << playerArray[i].getName() << endl;
		playerArray[i].startRoll();
		vector<string>temp = playerArray[i].getValues();
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == "Attack") {
				nbAttack++;
			}
		}
		cout << "Number of Attack rolled: " << nbAttack << endl;
		order[playerArray[i].getName()] = nbAttack;
	}
    auto cmp = [](const auto &p1, const auto &p2)
    {
        return p2.second < p1.second || !(p1.second < p2.second) && p1.first < p2.first;
    };

    set<pair<string, size_t>, decltype(cmp)> s(order.begin(), order.end(), cmp);

	cout << endl;
	cout << "Game will proceed in the following order of turns:" << endl;
	
    for (const auto &p : s)
    {
        std::cout << p.first << " ";
		for (int i = 0; i < this->playerArray.size(); i++) {
			if (p.first == this->playerArray[i].getName()) {
				this->orderedPlayerArray.push_back(playerArray[i]);
			}
		}
    }
	cout << endl << endl;
}

vector<Player> GameDriver::getPlayerArray() {
	return orderedPlayerArray;
}

void GameDriver::play(Deck deck, Map map) {

	bool activeGame = true;
	while (activeGame) {
		//for each player
		for (Player &player : this->getPlayerArray()) {
			this->currentPlayer = player;
			//1 roll the dice
			this->currentPhase = "Roll the dice step";
			notify();
			player.executeRollDice();

			//2 resolve the dice (mandatory)
			this->currentPhase = "Resolve the dice step";
			notify();
			player.executeResolveDice();
			//3 move
			this->currentPhase = "Move step";
			notify();
			player.executeMove(map);
			//4 buy card (optional)
			this->currentPhase = "Buy cards step";
			notify();
			player.executeBuyCards(deck);
			
			//5 turn
			if (player.getMonster().getVictoryPoints() == 20) {
				//if 20 vicotry points
				this->currentPhase = "The game has ended!";
				notify();
				activeGame = false;
			}
		}
		//if only one player left at the end
		if (this->getPlayerArray().size() <= 1) {
			activeGame = false;
		}
	}
}

#include "pch.h"
#include "GameDriver.h"


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

Map GameDriver::getMap()
{
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

	for (int i = 0; i < nbPlayers; i++) {
		cout << "Player " << i << ", what NAME would you like to use?" << endl;
		string playerName = string();
		cin >> playerName;
		Player player = Player(playerName);

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
	for (Player player : orderedPlayerArray) {
		player.chooseRegion(this->gameMap);
	}
}

void GameDriver::determineOrder() {
	this->playerArray;
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

    std::set < std::pair<string, size_t>, decltype( cmp )> s(order.begin(), order.end(), cmp);

	cout << endl;
	cout << "Game will proceed in the following order of turns:" << endl;

    for (const auto &p : s)
    {
        std::cout << p.first << " ";
		Player player = Player(p.first);
		this->orderedPlayerArray.push_back(player);
    }
    std::cout << std::endl;
}

vector<Player> GameDriver::getPlayerArray()
{
	return orderedPlayerArray;
}


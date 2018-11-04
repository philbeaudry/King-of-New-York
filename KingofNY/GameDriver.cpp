#include "pch.h"
#include "GameDriver.h"


GameDriver::GameDriver(){
}


GameDriver::~GameDriver() {
}

bool GameDriver::selectMap(string file) {
	this->map = Map(file);

	if (map.CreateMap()) {
		cout << "Map has been succesfuly loaded" << endl;
		return true;
	}
	else {
		cout << "Problem: Map not loaded succesfully" << endl;
	}
	return false;
}

Map GameDriver::getMap()
{
	return this->map;
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

		//TODO assign dice rolling facilities, create a deck of cards, and an empty hand of cards

		this->playerArray[i]  = player;
	}
	return true;
}

void GameDriver::printPlayers() {
	cout << "List of players:" << endl;
	for (int i = 0; i < nbPlayers; i++)
		cout << playerArray[i].getName() << endl;
}

void GameDriver::startup() {
	for (Player player : playerArray) {
		player.chooseRegion(this->map);
		this->map.graph.printGraph();
	}
}

void GameDriver::determineOrder() {
	srand(time(NULL));
	random_shuffle(playerArray.begin(), playerArray.end());

	int i = 1;
	cout << "Here is the order of Turns:" << endl;
	for (Player player : playerArray) {
		cout << i << " : " << player.getName() << endl;
		i++;
	}
}

vector<Player> GameDriver::getPlayerArray()
{
	return this->playerArray;
}


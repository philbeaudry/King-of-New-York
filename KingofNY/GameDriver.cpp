#include "pch.h"
#include "GameDriver.h"


GameDriver::GameDriver() {
}


GameDriver::~GameDriver() {
}

bool GameDriver::selectMap(string file) {
	Map map(file);
	if (map.CreateMap()) {
		cout << "Map has been succesfuly loaded" << endl;
		return true;
	}
	else {
		cout << "Problem: Map not loaded succesfully" << endl;
	}
	return false;
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
		cout << "Player " << i << ", what name would you like to use?" << endl;
		string *playerName = new string();
		cin >> *playerName;
		Player *player = new Player(*playerName);
		this->playerArray[i]  = *player;
	}
	return true;
}

void GameDriver::printPlayers() {
	for (int i = 0; i < nbPlayers; i++)
		cout << playerArray[i].getName() << endl;
}

void GameDriver::determineOrder() {
	srand(time(NULL));

	map<int, int> order;
	//6 black dice and the 2 green dice	
	int nbAttack = 0;
	for (int i = 0; i < nbPlayers; i++) {
		nbAttack = 0;
		for (int i = 0; i < 8; i++) {
			if ((rand() % 6+1) == 1) {
				nbAttack++;
			}
		}
		order[i] = nbAttack;
	}

}


#pragma once
#include <string>
#include "Map.h"
#include "Player.h"
#include "Dice.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class GameDriver
{
public:
	int nbPlayers;
	vector<Player> playerArray;
	GameDriver();
	~GameDriver();

	bool selectMap(string file);

	bool loadPlayers();

	void printPlayers();

	bool startup();

	void determineOrder();

	void chooseRegion(Player player);

	void setPieces();

};
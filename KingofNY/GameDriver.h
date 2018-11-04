#pragma once
#include <string>
#include "Map.h"
#include "Player.h"
#include "Dice.h"
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <utility>

using namespace std;

class GameDriver
{
public:
	int nbPlayers;
	vector<Player> playerArray;
	vector<Player> orderedPlayerArray;
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
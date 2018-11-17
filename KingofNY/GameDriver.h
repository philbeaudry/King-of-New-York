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
#include "Strategies/Human.h"

using namespace std;

class GameDriver
{
public:
	int nbPlayers;
	vector<Player> playerArray;
	vector<Player> orderedPlayerArray;
	Map gameMap;

	GameDriver();
	~GameDriver();

	bool selectMap(string file);
	Map getMap();

	bool loadPlayers();

	void printPlayers();

	void startup();

	void determineOrder();

	vector<Player> getPlayerArray();
};
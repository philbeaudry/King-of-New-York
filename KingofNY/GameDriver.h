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
	Map map;

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
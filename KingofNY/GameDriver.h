#pragma once
#include <string>
#include "Map.h"
#include "Player.h"
#include "Dice.h"
#include "Observer.h"
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <utility>
#include "Human.h"
#include "Agressive.h"
#include "Moderate.h"
#include "Subject.h"

using namespace std;

class GameDriver : public Subject
{
public:
	vector<class Observer*> observerList;
	int nbPlayers;
	Player currentPlayer;
	string currentPhase;
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

	void play(Deck,Map);

	vector<Player> getPlayerArray();
};
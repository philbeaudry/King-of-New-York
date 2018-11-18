// KingofNY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Dice.h"
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "Map.h"
#include "GameDriver.h"
#include "phaseObserver.h"

using namespace std;

int main() {
	srand(time(NULL));


	GameDriver gameDriver;
	phaseObserver phaseObs(&gameDriver);

	cout << "Loading valid map" << endl;
	cout << gameDriver.selectMap("kingofNY.map") << endl;

	//select players (number)
	gameDriver.loadPlayers();

	//Create deck of cards
	Deck deck;
	deck.generateDeck();
	
	//Demo Part 2- Startup Phase
	gameDriver.determineOrder();
	gameDriver.startup();
	//todo show map with players

	//Demo part 3 -- main game loop
	Map gameMap = gameDriver.getMap();

	gameDriver.play(deck,gameMap);


	return 0;
	
}
	


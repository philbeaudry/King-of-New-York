// KingofNY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Dice.h"
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "Map.h"
#include "GameDriver.h"

using namespace std;

int main() {

	GameDriver gameDriver;
	//part 1
	gameDriver.selectMap("kingofNY.map");
	gameDriver.loadPlayers();
	gameDriver.printPlayers();

	//part 2
	gameDriver.determineOrder();
	gameDriver.startup();


	vector<Player> players;

	//Main game loop
	Map map = gameDriver.getMap();

	//map.graph.printGraph();

	bool activeGame = true;
	while (activeGame) {
		//for each player
		for (Player player : players) {
			//1 roll the dice
			
			//2 resolve the dice

			//3 move
			player.move(map);
			

			//4 buy card

			//5 turn
			//if 20 vicotry points
		}

		//nunber of players = 1
	}

	string hello;
	cin >> hello;
	return 0;
	
}
	


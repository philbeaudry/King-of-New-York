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
	srand(time(NULL));

	//Demo Part 1- Game Start
	cout << endl << "Part 1 Demo: game start" << endl;
	GameDriver gameDriver;

	cout << "testing invalid file" << endl;
	cout << gameDriver.selectMap("badFile400.map") << endl;

	cout << "Loading valid map" << endl;
	cout << gameDriver.selectMap("kingofNY.map") << endl;

	//select players (number)
	gameDriver.loadPlayers();

	//Create deck of cards
	Deck deck;
	deck.generateDeck();
	
	//Demo Part 2- Startup Phase
	cout << endl << "Part 2 Demo: startup phase" << endl;
	gameDriver.determineOrder();
	gameDriver.startup();
	//todo show map with players


	//Demo part 3 -- main game loop
	cout << endl << "Part 3 Demo: main loop" << endl;
	bool activeGame = true;
	while (activeGame) {
		//for each player
		for (Player player: gameDriver.getPlayerArray()) {
			cout << endl << "-------" << endl << "Now its " << player.getName() << " turn!" << endl << "-------" << endl;
			//1 roll the dice
			player.RollDice();

			//2 resolve the dice (mandatory)
			player.ResolveDice();

			//3 move
			player.move(gameDriver.getMap());

			//4 buy card (optional)
			player.buyCards(deck);

			//5 turn
			if (player.getMonster().getVictoryPoints() == 20) {
				//if 20 vicotry points
				activeGame = false;
			}			
		}
		//if only one player left at the end
		if (gameDriver.getPlayerArray().size() <= 1) {
			activeGame = false;
		}

		//to put an end to the game
		string answer;
		cout << endl <<"Would you like to continue playing(yes, no)?";
		cin >> answer;
		while (answer != "yes" && answer != "no" && answer != "Yes" && answer != "No") {
			cout << "Invalid answer. Please enter yes or no: ";
			cin >> answer;
		}
		if (answer == "yes" || answer == "Yes") {
			activeGame = false;
		}
	}

	//for individual demo purposes.

	//Part 4 - Main game loop: roll the dice and resolve the dice
	cout << endl << "Part 4 Demo : roll and resolve dice" << endl;
	Player player2;
	player2.RollDice();
	player2.ResolveDice();

	//Part 5 - Main game loop: Move
	cout << endl << "Part 5 Demo : Move" << endl;
	player2.move(gameDriver.gameMap);

	//Demo Part 6 - Buy Cards
	cout << endl << "Part 6 Demo: buy cards" << endl;
	Player player3;
	Deck deck2;

	deck2.generateDeck();
	player3.buyCards(deck);

	return 0;
	
}
	


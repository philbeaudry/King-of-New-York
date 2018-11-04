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
	
	
	//Demo Part 2- Startup Phase
	GameDriver gameDriver;

	gameDriver.selectMap("kingofNY.map");
	gameDriver.loadPlayers();
	gameDriver.determineOrder();

	//Demo Part 3-Main Game Loop
	//bool activeGame = true;
	//while (activeGame) {
	//	//for each player
	//	for (int i = 0; i < 6; i++) {
	//		//1 roll the dice
	//		
	//		//2 resolve the dice

	//		//3 move

	//		//4 buy card

	//		//5 turn
	//		//if 20 vicotry points
	//		activeGame = false;
	//	}

	//	//nunber of players = 1
	//	activeGame = false;
	//}


	//Demo Part 6 - Buy Cards
	/*Player player;
	Player player2;
	Deck deck;

	player.RollDice();
	player2.RollDice();
	deck.generateDeck();
	player.buyCards(deck);*/
	return 0;

}
	


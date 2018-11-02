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

	Player player;
	Deck deck;
	deck.generateDeck();
	player.buyCards(deck);

	//GameDriver gameDriver;

	//gameDriver.selectMap("kingofNY.map");
	//gameDriver.loadPlayers();
	//gameDriver.printPlayers();
	//gameDriver.determineOrder();

	////Main game loop
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
	return 0;

}
	


// KingofNY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Dice.h"
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "Map.h"

using namespace std;

int main()
{

	Player player;
	Deck deck;
	
	deck.generateDeck();

	player.buyCards(deck);
	/*Monster captainFish = Monster("Captain Fish");
	player.monsterCard = captainFish;

	player.RollDice();
	player.ResolveDice();
	
	cout << player.monsterCard.getVictoryPoints();*/

	////DEMO PART 1 the Graph and node class  
	//cout << "******************** DEMO for Part 1" << endl;
	//Graph graph(5);

	//vector<int> connections;

	//Node manhattan = Node(0, "manathan", 0, 0, false, connections, false);
	//Node brooklyn = Node(1, "brooklyn", 0, 0, false, connections, true);
	//Node queens = Node(2, "queens", 0, 0, false, connections, true);
	//Node bronx = Node(3, "bronx", 0, 0, false, connections, true);
	//Node statenisland = Node(4, "statenisland", 0, 0, false, connections, true);

	////Interpret: To get to Manhattan, I can come from id: 1 (brooklyn)
	//graph.addEdge(manhattan, 1);
	//graph.addEdge(manhattan, 2);
	//graph.addEdge(manhattan, 3);
	//graph.addEdge(manhattan, 4);
	//graph.addEdge(statenisland, 1);
	//graph.addEdge(statenisland, 0);
	//graph.addEdge(brooklyn, 4);
	//graph.addEdge(brooklyn, 2);
	//graph.addEdge(brooklyn, 0);
	//graph.addEdge(bronx, 2);
	//graph.addEdge(bronx, 0);
	//graph.addEdge(queens, 3);
	//graph.addEdge(queens, 0);

	//cout << "Here are to possible movements from all positions" << endl;
	//graph.printGraph();

	//cout << endl << endl;


	////DEMO PART 2
	//cout << "************************DEMO for Part 2" << endl;
	//Map map("kingofNY.map");
	//if (map.CreateMap()) {
	//	cout << "Map has been succesfuly loaded" << endl;
	//}
	//else {
	//	cout << "Problem: Map not loaded succesfully" << endl;
	//}

	////non existing
	//Map Nomap("unexisting.map");
	//if (Nomap.CreateMap()) {
	//	cout << "Map has been succesfuly loaded" << endl;
	//}
	//else {
	//	cout << "  !!Problem: Map not loaded succesfully" << endl;
	//}

	//cout << endl << endl;

	////DEMO PART 3
	//cout << "************************DEMO for Part 3" << endl;

	//Player player;
	//player.RollDice();

	//cout << "Here are the dice values kept" << endl;
	//vector<string> dices = player.getDiceValues();
	//for (string die : dices) {
	//	cout << die << endl;
	//}

	//cout << endl << endl;

	////DEMO PART 4
	//cout << "******************** DEMO for Part 4" << endl;
	//Deck MainDeck;
	//MainDeck.generateDeck();
	//MainDeck.generateMonsters();
	//MainDeck.generateTokens();
	//MainDeck.generateTiles();

	//player.chooseMonster(MainDeck);
	//player.chooseRegion(map);

	//cout << "Testing adding a random Token to a player info" << endl;
	//player.addToken(MainDeck.getTokens()[1]);
	//for (Token token : player.getTokens()) {
	//	cout << "Token: " << token.getTokenType() << endl;
	//}

	//cout << "Here are the players current dice values" << endl;
	//for (string die : player.getDiceValues()) {
	//	cout << "Die: " << die << endl;
	//}

	//cout << "Running resolve dice method" << endl;
	//player.ResolveDice();


	//cout << endl << endl;

	//cout << "Postion that can be visited from the current position of the player" << endl << endl;
	//cout << "Current position " << player.getRegion().name << endl;
	//player.move(map);
	//cout << "New position " << player.getRegion().name << endl;

	//cout << endl << endl;
	//cout << "Buy card ( draws a card and gives it to a player): " << endl;
	//player.buyCard(MainDeck.drawCard());
	//for (Card card : player.getCards()) {
	//	cout << "Card: " << card.getName() << endl;
	//}

	//cout << endl << endl;

	////DEMO PART 5
	//cout << "************************DEMO for Part 5" << endl;

	//cout << "Here are all the cards in the deck: " << endl;
	//for (Card card : MainDeck.getDeck()) {
	//	cout << "Card: " << card.getName() << endl;
	//}
	//
	//cout << "Shuffling deck" << endl << endl;
	//MainDeck.shuffleDeck();
	//cout << endl << "Here are all the cards in the deck after the shuffle: " << endl;
	//for (Card card : MainDeck.getDeck()) {
	//	cout << "Card: " << card.getName() << endl;
	//}

	//cout << endl << endl;

	//for (Tile tile : MainDeck.getTiles()) {
	//	cout << "Tile state: " << tile.getState() << endl;
	//}
	//MainDeck.shuffleTiles();
	//cout << endl << "Here are all the tiles in the deck after the shuffle: " << endl;
	//for (Tile tile: MainDeck.getTiles()) {
	//	cout << "Tile stat: " << tile.getState() << endl;
	//}

	return 0;

}
	


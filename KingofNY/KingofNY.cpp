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
	//Dice dice1;
	//dice1.diceDriver();
	/*Player p1 = Player("John");
	
	p1.RollDice();
	p1.ResolveDice();
	*/

	//DEMO the Graph and node class  
	cout << "DEMO for Part 1" << endl;
	Graph graph(5);

	vector<int> connections;

	Node manhattan = Node(0, "manathan", 0, 0, false, connections);
	Node brooklyn = Node(1, "brooklyn", 0, 0, false, connections);
	Node queens = Node(2, "queens", 0, 0, false, connections);
	Node bronx = Node(3, "bronx", 0, 0, false, connections);
	Node statenisland = Node(4, "statenisland", 0, 0, false, connections);

	//Interpret: To get to Manhattan, I can come from id: 1 (brooklyn)
	graph.addEdge(manhattan, 1);
	graph.addEdge(manhattan, 2);
	graph.addEdge(manhattan, 3);
	graph.addEdge(manhattan, 4);
	graph.addEdge(statenisland, 1);
	graph.addEdge(statenisland, 0);
	graph.addEdge(brooklyn, 4);
	graph.addEdge(brooklyn, 2);
	graph.addEdge(brooklyn, 0);
	graph.addEdge(bronx, 2);
	graph.addEdge(bronx, 0);
	graph.addEdge(queens, 3);
	graph.addEdge(queens, 0);

	cout << "Here are to possible movements from all positions" << endl;
	graph.printGraph();

	cout << endl << endl;
	//DEMO for part Two
	cout << "DEMO for Part 2" << endl;
	Map map("kingofNY.map");

	cout << endl << endl;
	//Demo for the Deck
	cout << "DEMO for Part 3" << endl;
	Deck deck = Deck();
	deck.generateDeck();

	vector <Card> test = deck.getDeck();

	for (unsigned int i = 0; i < test.size(); i++) {
		string name = test[i].getName();
		cout << name << endl;
	}

	deck.shuffle();
	test = deck.getDeck();
	cout << "==============================";

	for (unsigned int i = 0; i < test.size(); i++) {
		string name = test[i].getName();
		cout << name << endl;
	}

}
	


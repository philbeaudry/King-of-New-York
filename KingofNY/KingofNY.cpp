// KingofNY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Dice.h"
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "Map.h"
#include <fstream>


using namespace std;

int main()
{
	//Dice dice1;
	//dice1.diceDriver();
	/*Player p1 = Player("John");
	
	p1.RollDice();
	p1.ResolveDice();
	*/

	ifstream board("board.map.json");
	string jsonString((std::istreambuf_iterator<char>(board)),
		(std::istreambuf_iterator<char>()));

	cout << jsonString << endl;

	//To DEMO the Graph and node class 
	int  nodes; 
	Graph graph(5);

	Node Manhattan = Node(0, "Manathan", "info");
	Node Brooklyn = Node(1, "Brooklyn", "info");
	Node Queens = Node(2, "Queens", "info");
	Node Bronx = Node(3, "Bronx", "info");
	Node StatenIsland = Node(4, "StatenIsland", "info");

	graph.addEdge(Manhattan, Brooklyn);
	graph.addEdge(Manhattan, Queens);
	graph.addEdge(Manhattan, Bronx);
	graph.addEdge(Manhattan, StatenIsland);
	graph.addEdge(StatenIsland, Brooklyn);
	graph.addEdge(Bronx, Queens);
	graph.addEdge(Queens, Brooklyn);

	cout << "Here are to posible movement from all positions \n";

	graph.printGraph();

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
	


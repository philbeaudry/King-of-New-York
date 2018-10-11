#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Map
{
public:
	Map(string mapFile);
	~Map();
};

class Node {
public:
	int id;
	string name;
	string info;

	Node(int id, string name, string info);
	~Node();
};

class Graph {
	int nbNodes; //number of nodes
	list<Node> *adjacency; //Pointer to an array of adjacency

public:
	Graph(int nbNodes);
	~Graph();
	void addEdge(Node nodeU, Node nodeV);
	void printGraph();
};






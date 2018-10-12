#pragma once
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

class Node {

public:
	int id;
	string name;
	int victoryPoints;
	int energyCube;
	bool health;
	vector<int> connections;

	Node();
	Node(int id, string name, int victoryPoints, int energyCube, bool health, vector<int>);
	~Node();
};

class Graph {
	int nbNodes; //number of node
	list<Node> *adjacency; //Pointer to an array of adjacency

public:
	Graph();
	Graph(int nbNodes);
	~Graph();
	void addEdge(Node nodeU, int nodeIdV);
	void printGraph();
	Node getNodeFromId(int id);
};

class Map {
	string filePath;
public:
	Graph graph;
	Map(string mapFile);
	~Map();
	bool CreateMap();
	vector<Node> getZones(json zones);
};






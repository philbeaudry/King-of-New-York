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
	bool start = false;
	vector<int> connections;
	int nbPlayers = 0;

	Node();
	Node(int id, string name, int victoryPoints, int energyCube, bool health, vector<int> , bool start);
	~Node();
};

class Graph {
	int nbNodes; //number of node
	int nbOfPlayersInManhattan = 0;
	list<Node> *adjacency; //Pointer to an array of adjacency
	vector<int> nbPlayersInZones;

public:
	Graph();
	Graph(int nbNodes);
	~Graph();
	void addEdge(Node nodeU, int nodeIdV);
	void printGraph();
	vector<Node> availableRegions(int id);
	vector<Node> getRegions();
	Node getNodeFromId(int id);
	int getNbOfPlayersInManhattan();
	void setNbOfPlayersInManhattan(int newNbOfPlayersInManhattan);
	int getNbOfPlayersInZone(int id);
	void setNbOfPlayersInZone(int id, int nbPlayers);
};

class Map {
	string filePath;
public:
	Graph graph;
	Map();
	Map(string mapFile);
	~Map();
	bool CreateMap();
	vector<Node> getZones(json zones);
};






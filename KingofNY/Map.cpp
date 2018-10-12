#include "pch.h"
#include "Map.h"


Map::Map(string filePath) {
	this->filePath = filePath;
}

Map::~Map() {
	// Deconstructor for map
	//cout << "Node deleted" << endl;
}

bool Map::CreateMap() {
	//Load the map
	try {
		ifstream stringJson(this->filePath);
		string jsonString((istreambuf_iterator<char>(stringJson)), (istreambuf_iterator<char>()));

		json zones = json::parse(jsonString);

		vector<Node> map = Map::getZones(zones);

		this->graph = Graph(map.size());

		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].connections.size(); j++) {
				this->graph.addEdge(map[map[i].connections[j]], i);
			}
		}
		return true;
	}
	catch (exception e) {
		cout << "Bad .map file! please try again with a valid Map";
		return false;
	}
	
}

vector<Node> Map::getZones(json zones) {
	int size = zones["zones"].size();
	vector<Node> map;
	map.resize(size);

	for (json zone : zones["zones"]) {
		int id = zone["id"];
		string name = zone["name"];
		int victoryPoints = zone["victoryPoints"];
		int energyCube = zone["energyCube"];
		bool health = zone["health"];
		bool start = zone["start"];
		vector<int> connections;

		int nbOfConnections = zone["connection"].size();
		connections.resize(nbOfConnections);

		for (int i = 0; i < nbOfConnections; i++) {
			connections[i] = zone["connection"][i];
		}

		Node *node = new Node(id, name, victoryPoints, energyCube, health, connections, start);
		map[id] = *node;
	}
	return map;
}

Node::Node() {}

Node::Node(int id, string name, int victoryPoints, int energyCube, bool health, vector<int> connections, bool start) {
	this->id = id;
	this->name = name;
	this->victoryPoints = victoryPoints;
	this->energyCube = energyCube;
	this->health = health;
	this->connections = connections;
	this->start = start;
}

Node::~Node(){
	// Deconstructor for node
	//cout << "Node deleted" << endl;
}

Graph::Graph() {
	//default constructor
}

Graph::Graph(int nbNodes) {
	this->nbNodes = nbNodes;
	adjacency = new list<Node>[nbNodes];
}

Graph::~Graph() {
	// Deconstructor for Graph
	//cout << "Graph deleted" << endl;
}

void Graph::addEdge(Node nodeU, int nodeIdV) {
	adjacency[nodeIdV].push_back(nodeU);
}

vector<Node> Graph::getRegions() {

	vector<Node> regions(this->nbNodes);

	for (int i = 0; i < this->nbNodes; i++) {
		regions[i] = getNodeFromId(i);
	}
	return regions;
}

void Graph::printGraph() {
	for (int i = 0; i < this->nbNodes; ++i) {
		cout << "Possible movement from the positon: " << getNodeFromId(i).name << endl;
		for (Node currentNode : adjacency[i]) {
			cout << " -> " << currentNode.name;
		}	
		cout << endl;
	}
}

vector<Node> Graph::availableRegions(int id) {

	vector<Node> availableRegions;

	if (getNodeFromId(id).start == false) {

	}
	for (Node currentNode : adjacency[id]) {
		if (currentNode.start == false) {
			if (currentNode.nbPlayers == 0) {
				availableRegions.clear();
				availableRegions.push_back(currentNode);
				return availableRegions;
			}
		}
		else if (currentNode.nbPlayers < 2) {
			availableRegions.push_back(currentNode);
		}
	}
	return availableRegions;
}

Node Graph::getNodeFromId(int id) {
	for (int i = 0; i < this->nbNodes; ++i) {
		for (Node currentNode : adjacency[i]) {
			if (currentNode.id == id) {
				return currentNode;
			}
		}
	}
	return Node();
}



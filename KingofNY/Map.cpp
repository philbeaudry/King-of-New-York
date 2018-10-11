#include "pch.h"
#include "Map.h"

Map::Map(string mapFile) {

}

Map::~Map() {
}


Node::Node(int id, string name, string info) {
	this->id = id;
	this->name = name;
	this->info = info;
}

Node::~Node() {}

Graph::Graph(int nbNodes) {
	this->nbNodes = nbNodes;
	adjacency = new list<Node>[nbNodes];
}

Graph::~Graph() {
	cout << "Graph was deleted" << endl;
}

void Graph::addEdge(Node nodeU, Node nodeV) {
	adjacency[nodeV.id].push_back(nodeU);
	adjacency[nodeU.id].push_back(nodeV);
}


void Graph::printGraph()
{
	for (int i = 0; i < this->nbNodes; ++i)
	{
		cout << "Possible movement from the positon: " << i << endl;
		for (auto currentNode : adjacency[i]) {
			cout << " -> " << currentNode.id;
		}	
		cout << endl;
	}
}



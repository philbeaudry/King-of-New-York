#pragma once
#include <string>

using namespace std;

class Map
{
public:
	Map();
	~Map();

	void insert(Node _node);
};

struct Node {
	string name;

	Node(string _name);
};


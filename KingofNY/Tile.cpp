#include "pch.h"
#include "Tile.h"

//default constructor
Tile::Tile()
{
	this->state = "Building";
	this->type = "";
	this->durability = 0;
	this->reward = 0;
}

//
Tile::Tile(string state, string type, int durability, int reward)
{
	this->state = state;
	this->type = type;
	this->durability = durability;
	this->reward = reward;
}

//destructor
Tile::~Tile()
{
}

//method called when building is destoryed and must be flipped to its unit side
void Tile::flip() {
	this->state = "Unit";
	if (this->durability == 1) {
		this->type = "Infantry";
	}
	else if (this->durability == 2) {
		this->type = "Jet";
	}
	else if (this->durability == 3) {
		this->type = "Tank";

	}
}

string Tile::getState() {
	return this->state;
}

string Tile::getType() {
	return this->type;
}




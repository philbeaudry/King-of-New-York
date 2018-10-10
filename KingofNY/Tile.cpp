#include "pch.h"
#include "Tile.h"


Tile::Tile()
{
	this->state = "Building";
	this->durability = 0;
	this->reward = 0;
}

Tile::Tile(string state,int durability, int reward)
{
	this->state = "Building";
	this->durability = 0;
	this->reward = 0;
}

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


Tile::~Tile()
{
}

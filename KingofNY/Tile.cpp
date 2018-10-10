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
}


Tile::~Tile()
{
}

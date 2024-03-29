#include "pch.h"
#include "Card.h"

//default constructor
Card::Card()
{
	this->name = "";
	this->cost = 0;
	this->effect = "";
	this->howToPlay = "";
}

//destructor
Card::~Card()
{
}

//returns card name
string Card::getName() {
	return this->name;
}

//returns cost
int Card::getCost() {
	return this->cost;
}

string Card::getHow()
{
	return this->howToPlay;
}

string Card::getEffect()
{
	return this->effect;
}

//constructor with name param
Card::Card(string cardName)
{
	this->name = cardName;
	this->cost = 0;
	this->effect = "";
	this->howToPlay = "";
}

//constructor
Card::Card(string cardName, int cardCost, string cardEffect)
{
	this->name = cardName;
	this->cost = cardCost;
	this->effect = cardEffect;
}




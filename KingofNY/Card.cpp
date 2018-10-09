#include "pch.h"
#include "Card.h"

Card::Card()
{
	this->name = "";
	this->cost = 0;
	this->effect = "";
	this->howToPlay = "";
}

Card::~Card()
{
}

string Card::getName() {
	return this->name;
}

Card::Card(string cardName)
{
	this->name = cardName;
	this->cost = 0;
	this->effect = "";
	this->howToPlay = "";
}

Card::Card(string cardName, int cardCost, string cardEffect, string cardHow)
{
	this->name = cardName;
	this->cost = cardCost;
	this->effect = cardEffect;
	this->howToPlay = cardHow;
}




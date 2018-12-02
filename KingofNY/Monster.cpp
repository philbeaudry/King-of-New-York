#include "pch.h"
#include "Monster.h"


Monster::Monster()
{
	this->name = "blabla";
	this->lifePoints = 10;
	this->victoryPoints = 0;
}

Monster::Monster(string monsterName) {
	this->name = monsterName;
	this->lifePoints = 10;
	this->victoryPoints = 0;
}

Monster::~Monster()
{
}

string Monster::getName()
{
	return this->name;
}

int Monster::getVictoryPoints()
{
	return this->victoryPoints;
}

int Monster::getlifePoints()
{
	return this->lifePoints;
}

void Monster::incrementVictoryPoint(){
	this->victoryPoints++;
}

void Monster::decrementVictoryPoint(){
	this->victoryPoints--;
}

void Monster::modifyLifePoints(string change, int amount)
{
	if (change == "increase") {
		this->lifePoints +=  amount;
	}
	else if (change == "decrease") {
		this->lifePoints = this->lifePoints - amount;
	}
}

void Monster::modifyVictoryPoints(string change, int amount)
{
	if (change == "increase") {
		this->victoryPoints = this->victoryPoints + amount;
	}
	else if (change == "decrease") {
		this->victoryPoints = this->victoryPoints - amount;
	}
}



#include "../pch.h"
#include "Strategy.h"


//method that calls various method to handle dice resolution phase
void Strategy::resolveValue(string type, int count) {
	if (type == "Energy") {
		solveEnergy(count);
	}
	else if (type == "Attack") {
		solveAttack(count);
	}
	else if (type == "Destruction") {
		solveDestruction(count);
	}
	else if (type == "Heal") {
		solveHeal(count);
	}
	else if (type == "Celebrity") {
		solveCelebrity(count);
	}
	else if (type == "Ouch!") {
		solveOuch(count);
	}
}

//increments player's energy count
void Strategy::solveEnergy(int count)
{
	this->energyCount += count;
}

//resolves attack effect
void Strategy::solveAttack(int count)
{
}

//resolves destruction effect
void Strategy::solveDestruction(int count)
{
}

//resolves heal effect
void Strategy::solveHeal(int count)
{
	int HP = this->getMonster().getlifePoints();
	if (HP >= 10) {
		cout << "Your monster has already the maximum amount of health points!" << endl;
	}
	else {
		this->monsterCard.modifyLifePoints("increase", count);
		int HP2 = this->getMonster().getlifePoints();
		cout << "Your monster now has " << HP2 << " health points!" << endl;
	}
}

//resolves celebrity effect
void Strategy::solveCelebrity(int count)
{
	int surplus = count - 3;

	if (this->hasSuperstar() == true) {
		this->monsterCard.modifyVictoryPoints("increase", surplus);
	}
	else if (count < 3) {
		cout << "You have rolled less than 3 Celebrity dice, nothing happens!";
	}
	else if (count >= 3) {
		if (this->hasSuperstar() == false) {
			this->setSuperStar("true");
			this->monsterCard.modifyVictoryPoints("increase", surplus);
		}
	}
}

//resolves ouch effect
void Strategy::solveOuch(int count)
{
}

//returns player Monster
Monster Strategy::getMonster()
{
	return monsterCard;
}
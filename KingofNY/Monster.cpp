#include "pch.h"
#include "Monster.h"


Monster::Monster()
{
	this->name = "";
}

Monster::Monster(string monsterName) {
	this->name = monsterName;
}

Monster::~Monster()
{
}

void Monster::generateMonsters()
{
	Monster captainFish = Monster("Captain Fish");
	Monster kong = Monster("Kong");
	Monster sheriff = Monster("Sheriff");
	Monster drakonis = Monster("Drakonis");
	Monster mantis = Monster("Mantis");
	Monster rob = Monster("Rob");

	monsters.push_back(captainFish);
	monsters.push_back(kong);
	monsters.push_back(sheriff);
	monsters.push_back(drakonis);
	monsters.push_back(mantis);
	monsters.push_back(rob);
}

vector <Monster> Monster::getMonsters() {
	return monsters;
}

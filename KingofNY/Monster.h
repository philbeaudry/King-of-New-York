#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Monster
{
	public:
		Monster();
		Monster(string);
		~Monster();
		void generateMonsters();
		string getName();
		int getVictoryPoints();
		int getlifePoints();
		void modifyLifePoints(string,int);
		void modifyVictoryPoints(string,int);
		vector <Monster> getMonsters();

	private:
		string name;
		int victoryPoints;
		int lifePoints;
		vector <Monster> monsters;

};



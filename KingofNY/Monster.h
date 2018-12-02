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
		string getName();
		int getVictoryPoints();
		int getlifePoints();
		void incrementVictoryPoint();
		void decrementVictoryPoint();
		void modifyLifePoints(string,int);
		void modifyVictoryPoints(string,int);

	private:
		string name;
		int victoryPoints;
		int lifePoints;
		

};



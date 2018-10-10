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
		vector <Monster> getMonsters();

	private:
		string name;
		vector <Monster> monsters;

};



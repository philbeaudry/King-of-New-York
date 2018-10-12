#pragma once
#include <string>

using namespace std;

class Tile
{
	public:
		Tile();
		Tile(string,string,int,int);
		~Tile();
		void flip();
		string getState();
		string getType();

	private:
		string state;
		string type;
		int durability;
		int reward;
};


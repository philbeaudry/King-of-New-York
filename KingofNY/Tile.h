#pragma once
#include <string>

using namespace std;

class Tile
{
	public:
		Tile();
		Tile(string,int,int);
		~Tile();
		void flip();

	private:
		string state;
		string type;
		int durability;
		int reward;
};


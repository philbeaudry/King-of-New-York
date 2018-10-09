#pragma once
#include <iostream>
#include <string>

using namespace std;

class Card
{
	public:
		Card();
		Card(string);
		Card(string, int, string, string);
		string getName();
		void setName();
		int getCost();
		void setCost();
		string getHow();
		void setHow();
		string getEffect();
		void setEffect();
		~Card();
		
	private:
		string name;
		int cost;
		string howToPlay;
		string effect;
};


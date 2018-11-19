#include "pch.h"
#include "statsObserver.h"
#include "GameDriver.h"
#include "Player.h"



statsObserver::statsObserver(GameDriver *gd) : Observer(gd)
{
}


statsObserver::~statsObserver()
{
}


void statsObserver::update() {
	cout << endl << "===================================" << endl;
	this->city.clear();
	buildNY();
	printCity();
	cout << endl << "===================================" << endl;
}

string statsObserver::buildBuilding()
{
	string building = "";
	for (int y = 1; y <= 3; y++) {
		for (int x = 1; x <= 10; x++) {
			building += "*";
		}
		building += "\n";
	}
	return building;
}

void statsObserver::printInfo(string cityName)
{
	for (int i = 0; i < this->city[cityName].size(); i++) {
		cout << "Monster Name: " << this->city[cityName][i].getMonster().getName();
		cout << " Victory Points: " << this->city[cityName][i].getMonster().getVictoryPoints();
	}
}
void statsObserver::printCity()
{
	vector<string> cities;
	cities.push_back("StatenIsland");
	cities.push_back("Brooklyn");
	cities.push_back("Queens");
	cities.push_back("Bronx");
	cities.push_back("Manhattan Lower");
	cities.push_back("Manhattan Upper");
	cities.push_back("Manhattan Midtown");

	for (int i = 0; i < cities.size(); i++) {
		cout << buildBuilding();
		cout << cities[i] << endl;
		printInfo(cities[i]);
		cout << endl;
	}
}
void statsObserver::buildNY()
{
	
	vector<Player> players = driver->getPlayerArray();

	for (int i = 0; i < players.size(); i++) {
		if (players[i].getRegion().name == "StatenIsland") {
			this->city["StatenIsland"].push_back(players[i]);
		}
		if (players[i].getRegion().name == "Brooklyn") {
			this->city["Brooklyn"].push_back(players[i]);
		}
		if (players[i].getRegion().name == "Queens") {
			this->city["Queens"].push_back(players[i]);
		}
		if (players[i].getRegion().name == "Bronx") {
			this->city["Bronx"].push_back(players[i]);
		}
		if (players[i].getRegion().name == "lower 2-4" || players[i].getRegion().name == "lower 5-6") {
			this->city["Manhattan Lower"].push_back(players[i]);
		}
		if (players[i].getRegion().name == "upper 2-4" || players[i].getRegion().name == "upper 5-6") {
			this->city["Manhattan Upper"].push_back(players[i]);
		}
		if (players[i].getRegion().name == "midtown 2-4" || players[i].getRegion().name == "midtown 5-6") {
			this->city["Manhattan Midtown"].push_back(players[i]);
		}
	
	}
}



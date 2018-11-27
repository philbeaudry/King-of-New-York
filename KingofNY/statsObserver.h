#pragma once
#include "Observer.h"
#include "Player.h"
#include "GameDriver.h"
#include <map>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class statsObserver : public Observer
{
public:
	map<string,vector<Player>> city;
	statsObserver(GameDriver *gd);
	~statsObserver();
	void update();
	string buildBuilding();
	void buildNY();
	void printInfo(string);
	void printCity();

private:
	GameDriver *subject;
};


#include "pch.h"
#include "phaseObserver.h"
#include "GameDriver.h"

using namespace std;

phaseObserver::phaseObserver(GameDriver *gd): Observer(gd)
{
}


phaseObserver::~phaseObserver()
{
}

void phaseObserver::update() {
	
	string player = driver->currentPlayer.getName();
	string phase = driver->currentPhase;

	cout << endl << endl;
	cout << "============================";
	cout << "Player " << player << " " << phase;
	cout << "============================";
	cout << endl;
}
#include "pch.h"
#include "phaseObserver.h"
#include "GameDriver.h"

using namespace std;

phaseObserver::phaseObserver(GameDriver *gd)
{
	subject = gd;
	subject->Attach(this);
}


phaseObserver::~phaseObserver()
{
}

void phaseObserver::update() {
	
	string player = subject->currentPlayer.getName();
	string phase = subject->currentPhase;

	cout << endl << endl;
	cout << "============================";
	cout << "Player " << player << " " << phase;
	cout << "============================";
	cout << endl;
}
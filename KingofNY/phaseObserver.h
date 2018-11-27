#pragma once
#include "Observer.h"
#include "GameDriver.h"
#include <iostream>
#include <string>

class phaseObserver : public Observer
{
public:
	phaseObserver(GameDriver *gd);
	~phaseObserver();
	void update();

private :
		GameDriver *subject;
};


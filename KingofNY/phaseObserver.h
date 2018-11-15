#pragma once
#include "observer.h"
#include <iostream>
#include <string>

class phaseObserver : public Observer
{
public:
	phaseObserver(GameDriver *gd);
	~phaseObserver();
	void update();
};


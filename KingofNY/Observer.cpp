#include "pch.h"
#include "Observer.h"
#include "GameDriver.h"


Observer::Observer(GameDriver *gd)
{
	this->driver = gd;

	driver->attach(this);	
}


Observer::~Observer()
{
}

void Observer::update()
{
}

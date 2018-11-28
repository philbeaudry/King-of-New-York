#pragma once
#include "Observer.h"
#include "Dice.h"
#include <iostream>
#include <string>

class DiceObserver : public Observer
{
public:
	DiceObserver(Dice *d);
	~DiceObserver();
	void update();

private:
	Dice *subject;
};


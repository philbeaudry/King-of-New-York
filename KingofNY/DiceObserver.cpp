#include "pch.h"
#include "DiceObserver.h"
#include "Dice.h"


DiceObserver::DiceObserver(Dice *d)
{
	subject = d;
	subject->Attach(this);
}

DiceObserver::~DiceObserver()
{
}

void DiceObserver::update()
{
	cout << "Values for this roll: " << endl;
	subject->displayDiceValues();
	cout << "Values kept during this turn so far: " << endl;
	subject->keepArray;
	subject->displayKeptValues();

}

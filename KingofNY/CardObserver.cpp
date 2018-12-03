#include "pch.h"
#include "CardObserver.h"

CardObserver::CardObserver(){
}

CardObserver::CardObserver(Card *s) {
	_subject = s;
	_subject->Attach(this);
}

CardObserver::~CardObserver(){
	_subject->Detach(this);
}

void CardObserver::update() {
	display();
}

void CardObserver::display() {
	cout << "Info about card: " + _subject->getName();
	cout << "Cost: " + _subject->getCost();
}

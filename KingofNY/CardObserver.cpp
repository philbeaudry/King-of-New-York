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
	string name = _subject->getName();
	cout << "Info about card: " + name;
}

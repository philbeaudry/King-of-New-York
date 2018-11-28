#pragma once
#include "Observer.h"
#include "Card.h"

class CardObserver : public Observer {
public:
	CardObserver();
	CardObserver(Card *s);
	~CardObserver();
	void update();
	void display();
private:
	Card *_subject;
};


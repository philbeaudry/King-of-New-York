#include "pch.h"
#include "Subject.h"
#include "Observer.h"

Subject::Subject(){
	_observer = new list<Observer*>;
}

Subject::~Subject(){
	delete _observer;
}

void Subject::Attach(Observer *o) {
	_observer->push_back(o);
}

void Subject::Detach(Observer * o) {
	_observer->remove(o);
}

void Subject::notify() {
	list<Observer *>::iterator i = _observer->begin();
	for (; i != _observer->end(); i++) {
		(*i)->update();
	}
}

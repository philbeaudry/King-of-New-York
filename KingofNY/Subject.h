#pragma once
#include <list>
using namespace std;

class Observer;

class Subject {
public:
	virtual void Attach(Observer *o);
	virtual void Detach(Observer *o);
	virtual void notify();
	Subject();
	~Subject();
private:
	list<Observer*> *_observer;
};


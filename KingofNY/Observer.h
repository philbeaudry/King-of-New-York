#pragma once

class Observer {
public:
	~Observer();
	virtual void update() = 0;
protected:
	Observer();
};

//
//class GameDriver;
//class Observer
//{
//	public:
//		GameDriver *driver;
//		Observer(GameDriver *gd);
//		~Observer();
//		virtual void update();	
//};


#pragma once

class GameDriver;
class Observer
{
	public:
		GameDriver *driver;
		Observer(GameDriver *gd);
		~Observer();
		virtual void update();	
};


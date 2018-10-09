#pragma once
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Deck
{
	const int MAX_CARDS = 64;

	public:

		Deck();
		~Deck();
		void generateDeck();
		void addCard(Card);
		void removeCard(int);
		int getSize();
		Card getCard(int);
		Card drawCard();
		bool isEmpty();
		void shuffle();
		vector<Card> getDeck();
	private:

		vector<Card> cardDeck;

	
};


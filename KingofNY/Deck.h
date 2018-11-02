#pragma once
#include "Card.h"
#include "Monster.h"
#include "Token.h"
#include "Tile.h"
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
		void removeTop();
		int getSize();
		Card getCard(int);
		void drawCard();
		bool isEmpty();
		void shuffleDeck();
		vector<Card> getDeck();
		void generateMonsters();
		vector<Monster> getMonsters();
		void generateTokens();
		vector<Token> getTokens();
		void generateTiles();
		void shuffleTiles();
		vector<Tile> getTiles();
		vector<Card> availCards;

	private:

		vector<Card> cardDeck;
		vector<Monster> monsters;
		vector<Token> tokens;
		vector<Tile> tiles;
	
};


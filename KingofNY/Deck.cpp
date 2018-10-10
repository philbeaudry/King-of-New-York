#include "pch.h"
#include "Deck.h"



Deck::Deck()
{
}


Deck::~Deck()
{
}

void Deck::generateDeck() {

	int count = 0;
	while (cardDeck.size() != Deck::MAX_CARDS)
	{
		string name = "Card" + to_string(count);
		cardDeck.push_back(Card(name));
		count++;
	}

}

	bool Deck::isEmpty()
	{
		return cardDeck.empty();
	}

	void Deck::addCard(Card theCard)
	{
		cardDeck.push_back(theCard);
	}

	void Deck::removeCard(int i)
	{

		cardDeck.erase(cardDeck.begin() + i);
	}

	vector <Card> Deck::getDeck() {
		return cardDeck;
	}

	void Deck::shuffleDeck() {
		srand(time(NULL));
		random_shuffle(this->cardDeck.begin(), this->cardDeck.end());
	}

	Card Deck::getCard(int i)
	{
		return cardDeck.at(i);
	}

	Card Deck::drawCard()
	{
		Card theCard = cardDeck.front();
		cardDeck.erase(cardDeck.begin());
		return theCard;
	}

	vector <Monster> Deck::getMonsters() {
		return monsters;
	}

	void Deck::generateMonsters()
	{
		Monster captainFish = Monster("Captain Fish");
		Monster kong = Monster("Kong");
		Monster sheriff = Monster("Sheriff");
		Monster drakonis = Monster("Drakonis");
		Monster mantis = Monster("Mantis");
		Monster rob = Monster("Rob");

		monsters.push_back(captainFish);
		monsters.push_back(kong);
		monsters.push_back(sheriff);
		monsters.push_back(drakonis);
		monsters.push_back(mantis);
		monsters.push_back(rob);
	}

	vector<Token> Deck::getTokens()
	{
		return tokens;
	}

	void Deck::generateTokens() {

		for (int i = 0; i < 13; i++) {
			tokens.push_back(Token("Web"));
			tokens.push_back(Token("Jinx"));
		}

		for (int i = 0; i < 5; i++) {
			tokens.push_back(Token("Souvenir"));
		}

		for (int i = 0; i < 15; i++) {
			tokens.push_back(Token("Carapace"));
		}

	}
		void Deck::generateTiles() {

			for (int i = 0; i < 45; i++) {
				tiles.push_back(Tile("Building",0,0));
				
			}
		}
	

	vector<Tile> Deck::getTiles()
	{
		return tiles;
	}

	void Deck::shuffleTiles() {
		srand(time(NULL));
		random_shuffle(this->tiles.begin(), this->tiles.end());
	}


	/*int Deck::getSize()
	{
		return cardDeck.size();
	}*/




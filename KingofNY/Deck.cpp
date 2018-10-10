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

	void Deck::shuffle() {
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

	/*int Deck::getSize()
	{
		return cardDeck.size();
	}*/




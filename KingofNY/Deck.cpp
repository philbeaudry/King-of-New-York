#include "pch.h"
#include "Deck.h"


//default constructor
Deck::Deck()
{
}

//destructor
Deck::~Deck()
{
}

//generates a generic card deck
void Deck::generateDeck() {

	Card statueOfLiberty = Card("Statue of Liberty");
	Card superstar = Card("Superstar");
	int count = 0;
	while (cardDeck.size() != Deck::MAX_CARDS)
	{
		string name = "Card" + to_string(count);
		cardDeck.push_back(Card(name));
		count++;
	}

}

	//checks if deck is empty
	bool Deck::isEmpty()
	{
		return cardDeck.empty();
	}

	//adds a card to top of deck
	void Deck::addCard(Card theCard)
	{
		cardDeck.push_back(theCard);
	}

	//removes card at given index
	void Deck::removeCard(int i)
	{

		cardDeck.erase(cardDeck.begin() + i);
	}

	//returns deck
	vector <Card> Deck::getDeck() {
		return cardDeck;
	}

	//shuffles cards in deck
	void Deck::shuffleDeck() {
		srand(time(NULL));
		random_shuffle(this->cardDeck.begin(), this->cardDeck.end());
	}

	//returns card at certain index
	Card Deck::getCard(int i)
	{
		return cardDeck.at(i);
	}

	//returns card at the top of deck
	Card Deck::drawCard()
	{
		Card theCard = cardDeck.front();
		cardDeck.erase(cardDeck.begin());
		return theCard;
	}

	//returns all available monsters
	vector <Monster> Deck::getMonsters() {
		return monsters;
	}

	//generates all monsters and inserts them into monster vector
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

	//returns all tokens
	vector<Token> Deck::getTokens()
	{
		return tokens;
	}

	//creates generic tokens
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

	//creates generic tiles
	void Deck::generateTiles() {

		for (int i = 0; i < 45; i++) {
			tiles.push_back(Tile("Building",0,0));
				
		}
	}
	
	//returns all tiles
	vector<Tile> Deck::getTiles()
	{
		return tiles;
	}

	//shuffles collection of tiles
	void Deck::shuffleTiles() {
		srand(time(NULL));
		random_shuffle(this->tiles.begin(), this->tiles.end());
	}


	/*int Deck::getSize()
	{
		return cardDeck.size();
	}*/




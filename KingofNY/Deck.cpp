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

	Card violentStar = Card("Violent Star",3,"keep");
	cardDeck.push_back(violentStar);
	Card sharpShooter = Card("Sharp Shooter", 4, "keep");
	cardDeck.push_back(sharpShooter);
	Card otherWorld = Card("Of Another World", 6, "keep");
	cardDeck.push_back(otherWorld);
	Card extraHead = Card("Extra Head", 7, "keep");
	cardDeck.push_back(extraHead);
	Card egoTrap = Card("Ego Trap", 3, "keep");
	cardDeck.push_back(egoTrap);
	Card hailingCabs = Card("Hailing Cabs", 5, "keep");
	cardDeck.push_back(hailingCabs);
	Card nextStage = Card("Next Stage", 4, "discard");
	cardDeck.push_back(nextStage);
	Card powerSub = Card("Power Substation", 5, "discard");
	cardDeck.push_back(powerSub);
	Card generalEllis = Card("General Ellis", 5, "discard");
	cardDeck.push_back(generalEllis);
	Card nyMarathon = Card("New York Marathon", 6, "discard");
	cardDeck.push_back(nyMarathon);
	Card airFroceOne = Card("Air Force One", 6, "discard");
	cardDeck.push_back(airFroceOne);
	Card subway = Card("Subway", 10, "discard");
	cardDeck.push_back(subway);

	shuffleDeck();
	for (int i = 0; i < 3; i++) {
		drawCard();
	}
	/*int count = 0;
	while (cardDeck.size() != Deck::MAX_CARDS)
	{
		string name = "Card" + to_string(count);
		cardDeck.push_back(Card(name));
		count++;
	}*/

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
	void Deck::removeTop()
	{
		availCards.pop_back();
	}

	void Deck::removeMonster(int j)
	{
		monsters.erase(monsters.begin() + j);
	}

	void Deck::removeCard(int j)
	{
		availCards.erase(availCards.begin() + j);
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
	void Deck::drawCard()
	{
		if (cardDeck.empty()) {
			cout << "No more cards available to draw!";
		}
		else {
			Card theCard = cardDeck.front();
			cardDeck.erase(cardDeck.begin());
			this->availCards.push_back(theCard);
		}
		
	}

	//returns all available monsters
	vector<Monster> Deck::getMonsters() {
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
			string name = "Building" + to_string(i);
			tiles.push_back(Tile(name, "", 0,0));
				
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




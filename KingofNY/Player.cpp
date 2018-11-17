#include "pch.h"
#include "Player.h"

//default constructor
Player::Player() {
	playerName = "";
}

Player::Player(Strategy * initStrategy) {
	this->strategy = initStrategy;
}

void Player::setStrategy(Strategy * newStrategy) {
	this->strategy = newStrategy;
}

//constructor
Player::Player(string name) {
	playerName = name;
}

//destructor
Player::~Player() {}

void Player::executeRollDice() {
	this->strategy->RollDice();
}

void Player::executeResolveDice() {
	this->strategy->ResolveDice();
}

void Player::executeMove(Map & map) {
	this->strategy->move(map);
}

void Player::executeBuyCards(Deck & deck) {
	this->strategy->buyCards(deck);
}

//returns player name
string Player::getName() {
	return playerName;
}
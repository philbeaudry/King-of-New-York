#include "pch.h"
#include "Player.h"

Player::Player(Strategy * initStrategy, string name) {
	this->strategy = initStrategy;
	this->strategy->setName(name);
}

void Player::setStrategy(Strategy * newStrategy) {
	this->strategy = newStrategy;
}

Player::Player(){
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
	return this->strategy->getName();
}

void Player::startRoll() {
	this->strategy->startRoll();
}

void Player::chooseRegion(Map &map) {
	this->strategy->chooseRegion(map);
}

Node Player::getRegion(){
	return this->strategy->getRegion();
}

vector<string> Player::getValues(){
	return this->strategy->getValues();;
}

void Player::chooseMonster(Deck &deck) {
	this->strategy->chooseMonster(deck);
}

Monster Player::getMonster() {
	return this->strategy->getMonster();
}

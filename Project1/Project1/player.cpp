// player.cpp starts here...

// Contains     ::          Funcion for storing Player data

#include "player.hpp"
#include <iostream>

// Default Constructor 

Player::Player() {
	name = "Unknown";
	bet = 0;
	cash = 1000;
	wins = 0;
	loses = 0;
}


// Returns name of Player
std::string Player::getName() {
	return name;
}

// Returns amount of bet
int Player::getBet() {
	return bet;
}

// Returns Player's cash amount
int Player::getCash() {
	return cash;
}

// Returns Player's statistic (number of wins)
int Player::getWins() {
	return wins;
}

// Returns Player's statistic (number of loses)
int Player::getLoses() {
	return loses;
}

// Sets name of Player
void Player::setName(std::string nm) {
	name = nm;
}

// Sets bet for game
void Player::setBet(int b) {
	cash -= b;
	bet += b;
}

// Adds cash to Player's cash amount
void Player::addCash(int c) {
	cash += c;
}

// Increments Player's number of wins by one
void Player::incrementWins() {
	wins += 1;
}

// Increments Player's number of loses by one
void Player::incrementLoses() {
	loses += 1;
}

// Clears player's hand
void Player::clearCards() {
	Human::clearCards();
	bet = 0;
}

// player.cpp ends here.....
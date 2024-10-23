#include <iostream>
#include <cstdlib>
#include "Player.h"

Player::Player(string name, int amountOfSpells) : Character(name) {
    //spells = new Spells[amountOfSpells];
}

Player::~Player() {
    //delete [] spells;
}

// Increases x stats with y values
void Player::increaseStats() {
    int amountOfStats = rand()%4 + 1;
    
}
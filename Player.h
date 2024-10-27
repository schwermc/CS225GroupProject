#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Character.h"
#include "Weapon.h"
#include "Spells.h"

using namespace std;

class Player: public Character {
private:
    Weapon weapon;
    Spells *spells;
    bool active;
	string classType, guild;
	int maxHealth, maxMana, strength, defense, speed, intelligence;
	float currentHealth, currentMana, manaRegen;

protected:
    
public:
    Player(string name, int amountOfSpells = 0);
    void deleteSpells();
    void increaseStats();
    // Change functions
    // Get functions
};

#endif

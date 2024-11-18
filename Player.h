#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Character.h"
#include "Weapon.h"
#include "Spells.h"

using namespace std;

class Player: public Character {
private:
	Weapon weapon;
	vector<Spells> spells;
	string classType, guild;
	int maxHealth, maxMana, strength, defense, speed, intelligence;
	float currentHealth, currentMana, manaRegen;

public:
	Player();
	Player(string name, int amountOfSpells = 0);

	Weapon getWeapon() const;
	Spells getSpells(int index) const;
	string getClass() const;
	string getGuild() const;
	int getSpellSize() const;
	int getMaxHealth() const;
	int getMaxMana() const;
	int getStrength() const;
	int getDefense() const;
	int getSpeed() const;
	int getIntelligence() const;
	float getcurrentHealth() const;
	float getcurrentMana() const;
	float getManaRegen() const;
	int attack();
	
	void takeDamage(int damage);
	void setPlayer(string mainLanguage, string race, string sex, string classType, string guild, int age, int maxHealth, int maxMana, int strength,
	               int defense, int speed, int intelligence, float height, float weight, float currentHealth, float currentMana, float manaRegen);
	void setPlayerSpell(int index, string type, string attackType, int power, float attackRate);
	void setPlayerWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate);
	void increaseStats();
	void printStats();
};

#endif

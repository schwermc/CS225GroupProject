#include <iostream>
#include <cstdlib>
#include "Player.h"

Player::Player() { }

Player::Player(string name, int amountOfSpells) : Character(name) {
	Spells temp;
	for (int i = 0; i < amountOfSpells; i++)
		spells.push_back(temp);
}

Weapon Player::getWeapon() const {
	return weapon;
}

Spells Player::getSpells(int index) const {
	return spells[index];
}

string Player::getClass() const {
	return classType;
}

string Player::getGuild() const {
	return guild;
}

int Player::getSpellSize() const {
	return spells.size();
}

int Player::getMaxHealth() const {
	return maxHealth;
}

int Player::getMaxMana() const {
	return maxMana;
}

int Player::getStrength() const {
	return strength;
}

int Player::getDefense() const {
	return defense;
}

int Player::getSpeed() const {
	return speed;
}

int Player::getIntelligence() const {
	return intelligence;
}

float Player::getcurrentHealth() const {
	return currentHealth;
}

float Player::getcurrentMana() const {
	return currentMana;
}

float Player::getManaRegen() const {
	return manaRegen;
}

int Player::attack() {
	int damage = weapon.getAttackPower() + rand()%5;
	return damage;
}

void Player::takeDamage(int damage) {
	currentHealth -= damage;
	if (currentHealth <= 0) {
		maxHealth = 0;
		alive = false;
	}
}

void Player::setPlayer(string mainLanguage, string race, string sex, string classType, string guild, int age, int maxHealth, int maxMana, int strength, int defense,
                       int speed, int intelligence, float height, float weight, float currentHealth, float currentMana, float manaRegen) {
	this->Character::mainLanguage = mainLanguage;
	this->Character::race = race;
	this->Character::sex = sex;
	this->Character::age = age;
	this->Character::height = height;
	this->Character::weight = weight;

	this->classType = classType;
	this->guild = guild;
	this->maxHealth = maxHealth;
	this->maxMana = maxMana;
	this->strength = strength;
	this->defense = defense;
	this->speed = speed;
	this->intelligence = intelligence;
	this->currentHealth = currentHealth;
	this->currentMana = currentMana;
	this->manaRegen = manaRegen;
}

void Player::setPlayerSpell(int index, string type, string attackType, int power, float attackRate) {
	spells[index].setSpell(type, attackType, power, attackRate);
}

void Player::setPlayerWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate) {
	weapon.setWeapon(type, attackType, attackPower, defensePower, attackRate);
}

void Player::increaseStats() {
	int amountOfStats = rand()%4 + 1;
	int amountIncrease = 0;
	int increasedStat = 0;
	cout << name << "\'s stat(s) have increased!" << endl;

	for (int i = 0; i < amountOfStats; i++) {
		amountIncrease = rand()%7 + 1;
		increasedStat = rand()%6 + 1;
		
		switch(increasedStat) {
		case 1:
			maxHealth += amountIncrease;
			currentHealth = maxHealth;
			break;
		case 2:
			if (maxMana != 0) {
				maxMana += amountIncrease;
				currentMana = maxMana;
				manaRegen += amountIncrease/(manaRegen*7);
			}
			else {
				maxHealth += (amountIncrease/2 == 0)? 1 : amountIncrease/2;
				currentHealth = maxHealth;
			}
			break;
		case 3:
			strength += (amountIncrease/2 == 0)? 1 : amountIncrease/2;
			break;
		case 4:
			defense += (amountIncrease/2 == 0)? 1 : amountIncrease/2;
			break;
		case 5:
			speed += (amountIncrease/3 == 0)? 2 : amountIncrease/3;
			break;
		case 6:
			intelligence += (amountIncrease/3 == 0)? 2 : amountIncrease/3;
			break;
		}
	}
}

void Player::printStats() {
	cout << "***************************" << endl;
	cout.width(14);
	cout << left << "Name:" << name << endl;

	cout.width(14);
	cout << "Health:" << currentHealth << "/" << maxHealth << endl;

	if (maxMana != 0) {
		cout.width(14);
		cout << "Mana:" << currentMana<< "/" << maxMana << endl;
		cout.width(14);
		cout << "  Regen:" << manaRegen << endl;
	}

	cout.width(14);
	cout << "Strength:" << strength << endl;
	cout.width(14);
	cout << "Defense:" << defense << endl;
	cout.width(14);
	cout << "Speed:" << speed << endl;
	cout.width(14);
	cout << "Intelligence:" << intelligence << endl << endl;

	cout << getWeapon();

	for (int i = 0; i < spells.size(); i++) {
		if (i == 0)
			cout << "Spells:" << endl;
		cout << "   " << getSpells(i);
	}
}
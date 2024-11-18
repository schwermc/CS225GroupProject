#include <iostream>
#include "Weapon.h"

Weapon::Weapon() {
	type = "Kakute";
	attackType = "Close Combat";
	attackPower = 30;
	defensePower = 0;
	attackRate = 0.5;
}

void Weapon::setWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate) {
	this->type = type;
	this->attackType = attackType;
	this->attackPower = attackPower;
	this->defensePower = defensePower;
	this->attackRate = attackRate;
}

int Weapon::getAttackPower() {
	return attackPower;
}

ostream& operator<<(ostream& os, const Weapon& w) {
	os << w.type << " that is a " << w.attackType << " weapon that has " << w.attackPower << " attack power, " << w.defensePower << " defense power, and an attack rate of " << w.attackRate << endl;
	return os;
}


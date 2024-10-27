#include <iostream>
#include "Weapon.h"

Weapon::Weapon() { 
	type = "Kakute";
	attackType = "Close Combat";
	int attackPower = 30;
	int defensePower = 0;
	float attackRate = 0.5;
}

void Weapon setWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate) {
	this->type = type;
	this->attackType = attackType;
	this->attackPower = attackPower;
	this->defensePower = defensePower;
	this->attackRate = attackRate;
}

ostream& operator(ostream& os, const Weapon& w) {
	os << " is a/an " << w.type << " that is a " << w.attackType << " weapon that has " << w.attackPower << " attack power, " << w.defensePower << " defense power, and an attack rate of " << w.attackRate << endl;
	return os;
}


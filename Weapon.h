#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

using namespace std;

class Weapon {
private:
	string type, attackType;
	int attackPower, defensePower;
	float attackRate;

public:
	Weapon();
	void setWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate);
	int getAttackPower();
	friend ostream& operator<<(ostream&, const Weapon&);
};

#endif
#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>

using namespace std;

class Spells {
private:
	string type, attackType;
	int power;
	float attackRate;

public:
	Spells();
	void setSpell(string type, string attackType = "Melee", int power = 20, float attackRate = .5);
	int getPower();
	friend ostream& operator<<(ostream&, const Spells&);
};

#endif
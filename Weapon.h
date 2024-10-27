#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

using namespace std;

class Weapon {
private:
    string type, attackType;
	int attackPower, defensePower;
	float attackRate;
protected:
    
public:
    Weapon();
    void setWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate);
    friend ostream& operator(ostream&, const Weapon&)

};

#endif
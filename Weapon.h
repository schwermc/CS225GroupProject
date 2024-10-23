#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

using namespace std;

class Weapon {
private:
    string type;
	int attackType, attackPower, defensePower;
	float attackRate;
protected:
    
public:
    Weapon();
    ~Weapon();
};

#endif
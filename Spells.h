#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>

using namespace std;

class Spells {
private:
    string type;
	int attackType, attackPower, defensePower;
	float attackRate;
protected:
    
public:
    Spells();
    ~Spells();
};

#endif
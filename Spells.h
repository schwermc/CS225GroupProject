#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>

using namespace std;

class Spells {
private:
    string type, attackType;
	int power;
	float attackRate;
protected:
    
public:
    Spells();
    ~Spells();
    void setSpell(string type, string attackType = "Melee", int power = 20, float attackRate = .5);
    friend ostream& operator<<(ostream&, const Spells&);
};

#endif
#include <iostream>
#include "Spells.h"

Spells::Spells() {
    type = "Mage Hand";
    attackType = "Cantrip";
    power = 0;
    attackRate = 1;
}

//Spells::~Spells() { }

void Spells::setSpell(string type, string attackType, int power, float attackRate) {
    this->type = type;
    this->attackType = attackType;
    this->power = power;
    this->attackRate = attackRate;
}

ostream& operator<<(ostream &os, const Spells &s) {
    os << s.type << " is a/an " << s.attackType << " that has " << s.power << " attack powers, and can be cast every " << s.attackRate << " seconds." << endl;
    return os;
}
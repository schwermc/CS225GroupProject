#include <iostream>
#include "Dungeon.h"

void clearCin() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void display(const Character *c, cont string menu) {
    // case files?
    cout << "Name: " << c->getName() << "endl";
}
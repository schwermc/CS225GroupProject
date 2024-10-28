#include <iostream>
#include <fstream>
#include "Dungeon.h"

void clearCin() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void displayMenu(const string menu, Character *c1, Character *c2, Character *c3) {
	cout << "***************************" << endl;
	if (menu == "options") {
		cout << "(T)  Look at team" << endl;
		cout << "(R)  Look around the room" << endl;
		cout << "(Q)  Quit Game" << endl;
		cout << "What would you like to do? ";
	}
	else if (menu == "teams") {
		cout << "Which character would you like to look at?" << endl;
		cout << "(1)  " << c1->getName() << endl;
		cout << "(2)  " << c2->getName() << endl;
		cout << "(3)  " << c3->getName() << endl;
		cout << "(4)  Back to Option Screen" << endl;
		cout << "What would you like to do? ";
	}
	else if (menu == "look") {

	}
	else {
		cout << "No menu selected..." << endl;
	}
}

void printCharacter(Character *c) {
    ofstream file(c->getName() + ".txt");
    file << "Name:   " << c->getName() << endl;
    file << "Status: ";
    if (c->getAlive())
        file << "Alive" << endl;
    else
        file << "Closed" << endl;
    file.close();
}

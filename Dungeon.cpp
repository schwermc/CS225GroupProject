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
		cout << "There are enemies and Antodia here!" << endl;
		cout << "(1)  Fight the enemies" << endl;
		cout << "(2)  Talk to Antodia" << endl;
		cout << "(3)  Back to Option Screen" << endl;
		cout << "What would you like to do? ";
	}
	else
		throw "The proper menu was not selected!";
}

void battle(Player *p1, Player *p2, Player *p3) {
	cout << "You entered battle!" << endl;
}

void printCharacter(const Player &p) {
	ofstream file(p.getName() + ".txt");
	if (!file.is_open())
	    throw "File cannot open";
	
	file.width(14);
	file << left << "Name:" << p.getName() << endl;

	file.width(14);
	file << "Status:";
	if (p.getAlive())
		file << "Alive" << endl;
	else
		file << "Dead" << endl;

	file.width(14);
	file << "Health:" << p.getcurrentHealth() << "/" << p.getMaxHealth() << endl;

	if (p.getMaxMana() != 0) {
		file.width(14);
		file << "Mana:" << p.getcurrentMana() << "/" << p.getMaxMana() << endl;
		file.width(14);
		file << "  Regen:" << p.getManaRegen() << endl;
	}

	file.width(14);
	file << "STR:" << p.getStrength() << endl;
	file.width(14);
	file << "DEF:" << p.getDefense() << endl;
	file.width(14);
	file << "SPD:" << p.getSpeed() << endl;
	file.width(14);
	file << "INT:" << p.getIntelligence() << endl << endl;

	file.width(14);
	file << "Age:" << p.getAge() << endl;
	file.width(14);
	file << "Race:" << p.getRace() << endl;
	file.width(14);
	file << "Sex:" << p.getSex() << endl;
	file.width(14);
	file << "Height:" << p.getHeight() << endl;
	file.width(14);
	file << "Weight:" << p.getWeight() << endl;
	file.width(14);
	file << "Language:" << p.getLanguage() << endl << endl;

	file.width(14);
	file << "Class:" << p.getClass() << endl;
	file.width(14);
	file << "Guild:" << p.getGuild() << endl << endl;

	file.width(10);
	file << "Weapon:\n\t" << p.getWeapon();

	for (int i = 0; i < p.getSpellSize(); i++) {
		if (i == 0)
			file << "Spells:" << endl;
		file <<"   " << p.getSpells(i);
	}

	file.close();
}

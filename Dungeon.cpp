#include <iostream>
#include <fstream>
#include "Dungeon.h"
#include "Enemy.h"

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

void battle(Player* p1, Player* p2, Player* p3) {
	vector<Enemy> enemies;
	int amountOfEnemies = 3;
	int tempIndex = 0;
	string names[5] = {"Elf", "Orc", "Human", "Dragonborn", "Shapechanging"};
	enemies.resize(amountOfEnemies);
	for (int i = 0; i < amountOfEnemies; i++)
		enemies[i] = Enemy(names[rand() % 5]);

	cout << "You entered battle!" << endl;

	// Add turned baes using speed then attack rate
	do {
		tempIndex = rand() % amountOfEnemies;
		enemies[tempIndex].takeDamage(p1->attack());
		if (!enemies[tempIndex].getAlive()) {
			amountOfEnemies--;
			enemies.erase(enemies.begin() + tempIndex);
		}
		else
			p1->takeDamage(enemies[tempIndex].attack());

		if (p2->getAlive()) {
			tempIndex = rand() % amountOfEnemies;
			enemies[tempIndex].takeDamage(p2->attack());
			if (!enemies[tempIndex].getAlive()) {
				amountOfEnemies--;
				enemies.erase(enemies.begin() + tempIndex);
			}
			else
				p2->takeDamage(enemies[tempIndex].attack());
		}

		if (p3->getAlive()) {
			tempIndex = rand() % amountOfEnemies;
			enemies[tempIndex].takeDamage(p3->attack());
			if (!enemies[tempIndex].getAlive()) {
				amountOfEnemies--;
				enemies.erase(enemies.begin() + tempIndex);
			}
			else
				p3->takeDamage(enemies[tempIndex].attack());
		}
	}
	while (p1->getAlive() && (enemies[0].getAlive() || enemies[1].getAlive() || enemies[2].getAlive()));

	if (p1->getAlive())
		p1->increaseStats();
	if (p2->getAlive())
		p2->increaseStats();
	if (p3->getAlive())
		p3->increaseStats();
}

void printCharacter(const Player &p) {
	ofstream file(p.getName() + ".txt");
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

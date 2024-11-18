/****************************************************************************
* File(s):   Group Project
* Author:    Cassandra Schwerman & Margaret Hanson
* Purpose:   RPG Dungeon Game
* Version:   1.0 Nov 13, 2024
* Resources:
*   Spells: https://roll20.net/compendium/dnd5e/Eldritch%20Blast#content
*   Exit Codes: https://www.geeksforgeeks.org/exit-codes-in-c-c-with-examples/
*******************************************************************************/
#include <iostream>
#include <vector>
#include "Player.h"
#include "Npc.h"
#include "Enemy.h"
#include "Time.h"
#include "Dungeon.h"

using namespace std;

int main() {
	srand(time(0));
	Time gameTime;

	Npc antodia("Antodia");
	vector<Player> characters;
	vector<Player> party;
	characters.resize(5);
	party.resize(3);
	int index = 0;
	int list[3];
	char userInput = ' ';

	characters[0] = Player("Feno Beilar", 10);
	characters[0].setPlayer("Common", "High Elf", "Female", "Wizard", "Black Dynasty", 137, 8, 12, 10, 12, 30, 16, 5.83, 140.67, 8, 12, 0.6);
	characters[0].setPlayerWeapon("Darts", "Small Range", 6, 0, 0.6);
	characters[0].setPlayerSpell(1, "Prestidigitation", "Cantrip", 0, 10);
	characters[0].setPlayerSpell(2, "Ray of Frost", "Cantrip", 2, 0);
	characters[0].setPlayerSpell(3, "Shocking Grasp", "Cantrip", 8, 0);
	characters[0].setPlayerSpell(4, "Detect Magic", "Short Range", 0, 0);
	characters[0].setPlayerSpell(5, "Mage Armor", "Melee", 0, 1);
	characters[0].setPlayerSpell(6, "Magic Misslie", "Long Range", 12, 1);
	characters[0].setPlayerSpell(7, "Shield", "Self Spell", 0, 1);
	characters[0].setPlayerSpell(8, "Sleep", "Mid Range", 0, 1);
	characters[0].setPlayerSpell(9, "Thunderwave", "Short Range", 8, 0);

	characters[1] = Player("Cormo Mistmoon", 0);
	characters[1].setPlayer("Common", "Halfling", "Male", "Rogue", "Shadowgarde", 47, 9, 0, 8, 14, 25, 13, 4.42, 85.34, 9, 0, 0);
	characters[1].setPlayerWeapon("Shortbow", "Long Range", 6, 0, 1.4);

	characters[2] = Player("Vorom Riz", 0);
	characters[2].setPlayer("Common", "Human", "Male", "Paladin", "Fiends of Abandonment", 27, 12, 0, 16, 18, 30, 11, 5.5, 117, 12, 0, 0);
	characters[2].setPlayerWeapon("Battleaxe", "Melee", 8, 2, 1.6);

	characters[3] = Player("Erolith Wranxidor", 0);
	characters[3].setPlayer("Common", "Wood Elf", "Male", "Fighter", "Highstars", 95, 12, 0, 13, 14, 35, 10, 6.08, 148.32, 12, 0, 0);
	characters[3].setPlayerWeapon("Greatsword", "Melee", 12, 4, 1);

	characters[4] = Player("Kikrunli Hammerhead", 9);
	characters[4].setPlayer("Common", "Hill Dwarf", "Female", "Cleric", "Black Dynasty", 74, 11, 18, 14, 18, 25, 10, 3.92, 77.42, 11, 18, 1.84);
	characters[4].setPlayerWeapon("Mace", "Small Range", 6, 0, 1.15);
	characters[4].setPlayerSpell(0, "Guidance", "Cantrip", 0, 1);
	characters[4].setPlayerSpell(1, "Light", "Cantrip", 0, 0);
	characters[4].setPlayerSpell(2, "Sacred Flame", "Cantrip", 8, 0);
	characters[4].setPlayerSpell(3, "Bless", "Short Range", 0, 1);
	characters[4].setPlayerSpell(4, "Cure Wounds", "Melee", 0, 0);
	characters[4].setPlayerSpell(5, "Guiding Bolt", "Long Range", 0, 1);
	characters[4].setPlayerSpell(6, "Healing Word", "Mid Range", 0, 0);
	characters[4].setPlayerSpell(7, "Sanctuary", "Short Range", 0, 1);
	characters[4].setPlayerSpell(8, "Shield of Faith", "Mid Range", 0, 10);

	for (const Player& key : characters) {
		cout << key.getName() << endl;
	}

	cout << endl << "Which character do what to be your main character? (0-4) : ";
	cin >> index;
	while(!cin || (index < 0 || 4 < index)) {
		clearCin();
		cout << endl << "That is not one of the five integers you can input." << endl;
		cout << "Please enter 0, 1, 2, 3, 4.\nWhat primary character do you want? ";
		cin >> index;
	}
	list[0] = index;

	cout << "What do you want you second character to be? ";
	cin >> index;
	while(!cin || (index < 0 || 4 < index)) {
		clearCin();
		cout << endl << "That is not one of the five integers you can input." << endl;
		cout << "Please enter 0, 1, 2, 3, 4.\nWhat secondary character do you want? ";
		cin >> index;
	}
	list[1] = index;

	cout << "What do you want the third character to be? ";
	cin >> index;
	while(!cin || (index < 0 || 4 < index)) {
		clearCin();
		cout << endl << "That is not one of the five integers you can input." << endl;
		cout << "Please enter 0, 1, 2, 3, 4.\nWhat triciary character do you want? ";
		cin >> index;
	}
	list[2] = index;

	for (int i = 0; i < 3; i++) {
		switch (list[i]) {
		case 0:
			party[i] = characters[0];
			break;
		case 1:
			party[i] = characters[1];
			break;
		case 2:
			party[i] = characters[2];
			break;
		case 3:
			party[i] = characters[3];
			break;
		case 4:
			party[i] = characters[4];
			break;
		}
	}

	try {
		cout << endl << "Your party lead is " << party[0].getName() << " with " << party[1].getName() << " and " << party[2].getName() << " being members!" << endl << endl;
		cout << "Your team as ented a skill testing dungeon! You are no longer able to use spells\n   unless they do damage or use any items!" << endl;
		displayMenu("options");

		// Loop through menus
		while (party[0].getAlive()) {
			cin >> userInput;

			switch (userInput) {
			case 'T':
				displayMenu("teams", &party[0], &party[1], &party[2]);
				cin >> userInput;
				switch (userInput) {
				case '1':
					party[0].printStats();
					displayMenu("options");
					break;
					
				case '2':
					party[1].printStats();
					displayMenu("options");
					break;
					
				case '3':
					party[2].printStats();
					displayMenu("options");
					break;
					
				case '4':
					displayMenu("options");
					break;
					
				default :
					displayMenu("options");
				}
				break;

			case 'R':
				displayMenu("look");
				cin >> userInput;
				switch (userInput) {
				case '1':
					battle(&party[0], &party[1], &party[2]);
					if (party[0].getAlive())
						displayMenu("options");
					break;
					
				case '2':
					cout << endl << "Antodia: \"";
					antodia.dialogue();
					cout << "\"" << endl;
					displayMenu("options");
					break;
					
				case '3':
					displayMenu("options");
					break;
					
				default :
					displayMenu(" ");
				}
				break;

			case 'Q':
				cout << "Would you like to print out " << party[0].getName() << "? (Y/N) ";
				cin >> userInput;
				if (userInput == 'Y')
					printCharacter(party[0]);
				gameTime.finishTime();
				cout << gameTime << endl;
				return 0;

			default :
				displayMenu(" ");
			}
		}
		cout << party[0].getName() << " died, your team members can no longer work together!" << endl;
		cout << "Would you like to print out " << party[0].getName() << "? (Y/N) ";
		cin >> userInput;
		if (userInput == 'Y')
			printCharacter(party[0]);
		gameTime.finishTime();
		cout << gameTime << endl;
	}
	
	catch (const char* c) {
		cout << "Exepetion caught: " << c << endl;
		gameTime.finishTime();
		cout << gameTime << endl;
	}

	return 0;
}
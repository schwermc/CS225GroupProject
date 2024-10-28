/****************************************************************************
* File(s):   Group Project
* Author:    Cassandra Schwerman & Margaret Hanson
* Purpose:   RPG Dungeon Game
* Version:   1.0 Nov 13, 2024
* Resources:
*   Dictionary: https://favtutor.com/blogs/cpp-dictionary
*   Spells: https://roll20.net/compendium/dnd5e/Eldritch%20Blast#content
*   Exit Codes: https://www.geeksforgeeks.org/exit-codes-in-c-c-with-examples/
*******************************************************************************/
#include <iostream>
#include <map>
#include "Player.h"
#include "Npc.h"
#include "Enemy.h"
#include "Dungeon.h"

using namespace std;

int main() {
	srand(time(0));
	map<string, Player> characters;
	Player party[3];

	// characters["High elf"] = Player("Feno Beilar", 10); // Wrong code
	characters.emplace("High elf", Player("Feno Beilar", 10));
	characters.emplace("Halfling", Player("Cormo Mistmoon", 0));
	characters.emplace("Human", Player("Vorom Riz", 0));
	characters.emplace("Wood elf", Player("Erolith Wranxidor", 0));
	characters.emplace("Hill Dwarf", Player("Kikrunli Hammerhead", 9));
	
	// Create party code here

	for (const pair<const string, Player>& key : characters) {
		cout << key.first << ": " << key.second.getName() << endl;
	}

	// Loop through menus
	while (party[0].getAlive() == true) {
		cin >> userInput;

		switch (userInput) {
		case 'T':
			displayMenu("teams", &party[0], &party[1], &party[2]);
			break;

		case 'R':
			displayMenu("look");
			break;

		case 'Q':
			cout << "Would you like to print out " << party[0].getName() << "? (Y/N) ";
			cin >> userInput;
			if (userInput == 'Y')
				printCharacter(&party[0]);

			for (pair<const string, Player>& key : characters) {
				key.second.deleteSpells();
			}
			
			return 0;
		}
	}

	cout << party[0].getName() << " died, your team members can no longer work together!" << endl;
	cout << "Would you like to print out " << party[0].getName() << "? (Y/N) ";
	cin >> userInput;
	if (userInput == 'Y')
		printCharacter(&party[0]);

	for (pair<const string, Player>& key : characters) {
		key.second.deleteSpells();
	}

	return 0;
}
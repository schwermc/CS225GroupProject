/****************************************************************************
* File(s):   Group Project
* Author:    Cassandra Schwerman & Margaret Hanson
* Purpose:   RPG Dungeon Game
* Version:   1.0 Nov 13, 2024
* Resources:
*   Dictionary: https://favtutor.com/blogs/cpp-dictionary
*   Spells: https://roll20.net/compendium/dnd5e/Eldritch%20Blast#content
*******************************************************************************/
#include <iostream>
#include <map>
#include "Player.h"
//#include "Npc.h"
//#include "Enemy.h"
//#include "Dungeon.h"

using namespace std;

int main() {
    srand(time(0));
    map<string, Player> characters;
    //Player party[3];
    
    // characters["High elf"] = Player("Feno Beilar", 10); // Wrong code
    characters.emplace("High elf", Player("Feno Beilar", 10));
    characters.emplace("Halfling", Player("Cormo Mistmoon", 0));
    characters.emplace("Human", Player("Vorom Riz", 0));
    characters.emplace("Wood elf", Player("Erolith Wranxidor", 0));
    characters.emplace("Hill Dwarf", Player("Kikrunli Hammerhead", 9));

     for (auto key : characters) {
         cout << key.first << ": " << key.second.getName() << endl;
     }
    
    cout << "Am I Thrid" << endl;
    
    return 0;
}
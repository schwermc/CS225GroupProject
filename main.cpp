/****************************************************************************
* File(s):   Group Project
* Author:    Cassandra Schwerman & Margaret Hanson
* Purpose:   RPG Dungeon Game
* Version:   1.0 Oct 13, 2024
* Resources:
*   Dictionary: https://favtutor.com/blogs/cpp-dictionary
*******************************************************************************/
#include <iostream>
#include <map>
#include "Player.h"
#include "Npc.h"
#include "Enemy.h"

using namespace std;

int main() {
    srand(time(0));
    map<string, Player> characters;
    //Player party[3];
    
    characters["High elf"] = Player("Feno Beilar", 10);
    characters["Halfling"] = Player("Cormo Mistmoon", 0);
    characters["Human"] = Player("Vorom Riz", 0);
    characters["Wood elf"] = Player("Erolith Wranxidor", 0);
    characters["Hill Dwarf"] = Player("Kikrunli Hammerhead", 9);
    
    for (auto key : characters) {
        cout << key.first << ": " << key.second.getName() << endl;
    }
}
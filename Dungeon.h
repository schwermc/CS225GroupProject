#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <climits>
#include "Player.h"

using namespace std;

void clearCin();

void displayMenu(const string menu, Character* = NULL, Character* = NULL, Character* = NULL);

void battle(Player*, Player*, Player*);

void printCharacter(const Player&);

#endif

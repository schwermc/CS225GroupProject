#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <climits>
#include "Character.h"

using namespace std;

void clearCin();

void displayMenu(const string menu, Character* = NULL, Character* = NULL, Character* = NULL);

void printCharacter(Character*);

#endif

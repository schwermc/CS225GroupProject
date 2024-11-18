#ifndef NPC_H
#define NPC_H

#include <iostream>
#include "Character.h"

using namespace std;

class Npc: public Character {
public:
	Npc(string name);
	void dialogue() const;
};

#endif
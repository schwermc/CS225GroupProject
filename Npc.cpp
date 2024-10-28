#include <iostream>
#include <cstdlib>
#include "Npc.h"

Npc::Npc(string name) : Character(name) { }

void Npc::Dialogue() {
	int dialogueNumber = rand() % 10;
	
	if (dialogueNumber == 0)
		cout << "0"

	if (dialogueNumber == 1)
		cout << "1";

	if (dialogueNumber == 2)
		cout << "2";

	if (dialogueNumber == 3)
		cout << "3";

	if (dialogueNumber == 4)
		cout << "4";

	if (dialogueNumber == 5)
		cout << "5";

	if (dialogueNumber == 6)
		cout << "6";

	if (dialogueNumber == 7)
		cout << "7";

	if (dialogueNumber == 8)
		cout << "8";

	if (dialogueNumber == 9)
		cout << "9";
}

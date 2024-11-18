#include <iostream>
#include <cstdlib>
#include "Npc.h"

Npc::Npc(string name) : Character(name) { }

void Npc::dialogue() const {
	int dialogueNumber = rand() % 10;

	if (dialogueNumber == 0)
		cout << "The greatest villains are the ones who think they\'re doing the right thing.";

	else if (dialogueNumber == 1)
		cout << "If a person stops fighting. They have truly given up...";

	else if (dialogueNumber == 2)
		cout << "So good at fitting in, that nobody ever saw them.";

	else if (dialogueNumber == 3)
		cout << "There are three types of people. Those who are true to themselves, those who act,\n   and those who are multi-faced.";

	else if (dialogueNumber == 4)
		cout << "Just because they refuse to diagnosis doesn\'t mean that the conditions weren\'t\n   there.";

	else if (dialogueNumber == 5)
		cout << "There is a difference between being lonely and being alone.";

	else if (dialogueNumber == 6)
		cout << "Don\'t apologize if you're going to take it back in the future.";

	else if (dialogueNumber == 7)
		cout << "Betrayal never comes from your enemy. It comes from the people you trust most.";

	else if (dialogueNumber == 8)
		cout << "Asking illogical people for logic is illogical.";

	else
		cout << "It\'s my opponent, not my enemy.";
}
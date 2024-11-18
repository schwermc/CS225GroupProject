#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "Character.h"

using namespace std;

class Enemy: public Character {
private:
	int maxHealth, strength, defense, speed;
	float currentHealth;

public:
	Enemy();
	Enemy(string name);
	int getcurrentHealth() const;
	int getSpeed() const;
	int attack();
	void takeDamage(int damage);
};

#endif
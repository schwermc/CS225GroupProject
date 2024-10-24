#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "Character.h"

using namespace std;

class Enemy : public Character {
private:
    int maxHealth, strength, defense, speed;
	float currentHealth;
protected:
    
public:
    Enemy(string name, int maxHealth = 100, float currentHealth = 100,
          int strength = 50, int defense = 50, int speed = 25);
    ~Enemy();
    int attack();
    void takeDamage();
};

#endif
#include <iostream>
#include <cstdlib>
#include "Enemy.h"

Enemy::Enemy(string name) : Character(name) {
	maxHealth = (rand() % 50) + 50;
	currentHealth = maxHealth;
	strength = (rand() % 25) + 25;
	defense = (rand() % 25) + 25;
	speed = (rand() % 10) + 25;
}

int Enemy::getcurrentHealth() const {
	return currentHealth;
}

int Enemy::getSpeed() const {
	return speed;
}

int Enemy::attack() {
	int damage = (strength) - (rand()%25 + 1)/speed;
	return damage;
}

void Enemy::takeDamage(int damage) {
	currentHealth -= damage;
	if (currentHealth <= 0) {
		maxHealth = 0;
		alive = false;
	}
}
#include <iostream>
#include <cstdlib>
#include "Enemy.h"

Enemy::Enemy(string name, int maxHealth, float currentHealth, int strength, int defense, int speed) : Character(name) {
    this->maxHealth = maxHealth;
    this->currentHealth = currentHealth;
    this->strength = strength;
    this->defense = defense;
    this->speed = speed;
}

Enemy::~Enemy() { }

int attack() {
    int damage = 0;
    return damage;    
}

void takeDamage() { }
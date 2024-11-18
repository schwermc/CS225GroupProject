#include <iostream>
#include "Character.h"

Character::Character() {
	name = "David";
	mainLanguage = "English";
	race = "Human";
	sex = "Male";
	age = 20;
	height = 5.8;
	weight = 167.4;
	alive = true;
}

Character::Character(string name, string mainLanguage, string race, string sex, int age, float height, float weight, bool alive) {
	this->name = name;
	this->mainLanguage = mainLanguage;
	this->race = race;
	this->sex = sex;
	this->age = age;
	this->height = height;
	this->weight = weight;
	this->alive = alive;
}

string Character::getName() const {
	return name;
}

string Character::getLanguage() const {
	return mainLanguage;
}

string Character::getRace() const {
	return race;
}

string Character::getSex() const {
	return sex;
}

int Character::getAge() const {
	return age;
}

float Character::getHeight() const {
	return height;
}

float Character::getWeight() const {
	return weight;
}

bool Character::getAlive() const {
	return alive;
}
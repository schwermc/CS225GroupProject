#include <iostream>
#include "Character.h"

int Character::PEOPLE = 5;

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

Character::Character(string name, string mainLanguage, string race, string sex,
                     int age, float height, float weight, bool alive) {
    this->name = name;
    this->mainLanguage = mainLanguage;
    this->race = race;
    this->sex = sex;
    this->age = age;
    this->height = height;
    this->weight = weight;
    this->alive = alive;
}

int Character::getPEOPLE() {
    return PEOPLE;
}

string Character::getName() const {
    return name;
}
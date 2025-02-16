#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

using namespace std;

class Character {
protected:
	string name, mainLanguage, race, sex;
	int age;
	float height, weight;
	bool alive;

public:
	Character();
	Character(string name, string mainLanguage = "English", string race = "Human", string sex = "Male", int age = 20, float height = 5.8,
	          float weight = 167.4, bool alive = true);
	int getPEOPLE();
	string getName() const;
	string getLanguage() const;
	string getRace() const;
	string getSex() const;
	int getAge() const;
	float getHeight() const;
	float getWeight() const;
	bool getAlive() const;
};

#endif
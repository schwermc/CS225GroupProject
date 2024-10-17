#ifndef CHARACTER_H
#define CHARACTER_H
/*
 * Naming the 'guard' as the file name in all caps and _H
 * 
 * Another way to name a 'guard' is last name then date(year/month/day) then time
 * Ex. schwerman_20241017_1123
 */

#include <iostream>

using namespace std;

class Character {
private:
    static int PEOPLE;

protected:
    string name, mainLanguage, race, sex;
	int age;
	float height, weight;
	bool alive;

public:
    Character();
    // Do function defaults within the .h file
    Character(string name, string mainLanguage = "English", string race = "Human",
              string sex = "Male", int age = 20, float height = 5.8,
              float weight = 167.4, bool alive = true);
    ~Character();
	int getPEOPLE();
};

#endif
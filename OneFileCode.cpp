#include <iostream>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <vector>

using namespace std;

/* Spells */
class Spells {
private:
	string type, attackType;
	int power;
	float attackRate;
protected:

public:
	Spells();
	void setSpell(string type, string attackType = "Melee", int power = 20, float attackRate = .5);
	friend ostream& operator<<(ostream&, const Spells&);
};

Spells::Spells() {
	type = "Mage Hand";
	attackType = "Cantrip";
	power = 0;
	attackRate = 1;
}

void Spells::setSpell(string type, string attackType, int power, float attackRate) {
	this->type = type;
	this->attackType = attackType;
	this->power = power;
	this->attackRate = attackRate;
}

ostream& operator<<(ostream &os, const Spells &s) {
	os << s.type << " is a/an " << s.attackType << " that has " << s.power << " attack powers, and can be cast every " << s.attackRate << " seconds." << endl;
	return os;
}

/* Weapons */
class Weapon {
private:
	string type, attackType;
	int attackPower, defensePower;
	float attackRate;
protected:

public:
	Weapon();
	void setWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate);
	friend ostream& operator<<(ostream&, const Weapon&);

};

Weapon::Weapon() {
	type = "Kakute";
	attackType = "Close Combat";
	attackPower = 30;
	defensePower = 0;
	attackRate = 0.5;
}

void Weapon::setWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate) {
	this->type = type;
	this->attackType = attackType;
	this->attackPower = attackPower;
	this->defensePower = defensePower;
	this->attackRate = attackRate;
}

ostream& operator<<(ostream& os, const Weapon& w) {
	os << w.type << " that is a " << w.attackType << " weapon that has " << w.attackPower << " attack power, " << w.defensePower << " defense power, and an attack rate of " << w.attackRate << endl;
	return os;
}

/* Character */
class Character {
protected:
	string name, mainLanguage, race, sex;
	int age;
	float height, weight;
	bool alive;

public:
	Character();
	Character(string name, string mainLanguage = "English", string race = "Human",
	          string sex = "Male", int age = 20, float height = 5.8,
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

/* Player */
class Player: public Character {
private:
	Weapon weapon;
	vector<Spells> spells;
	string classType, guild;
	int maxHealth, maxMana, strength, defense, speed, intelligence;
	float currentHealth, currentMana, manaRegen;

public:
	Player();
	Player(string name, int amountOfSpells = 0);
	
	Weapon getWeapon() const;
	Spells getSpells(int index) const;
	string getClass() const;
	string getGuild() const;
	int getSpellSize() const;
	int getMaxHealth() const;
	int getMaxMana() const;
	int getStrength() const;
	int getDefense() const;
	int getSpeed() const;
	int getIntelligence() const;
	float getcurrentHealth() const;
	float getcurrentMana() const;
	float getManaRegen() const;
	
	void setPlayer(string mainLanguage, string race, string sex, string classType,
	    string guild, int age, int maxHealth, int maxMana, int strength,
	    int defense, int speed, int intelligence, float height, float weight,
	    float currentHealth, float currentMana, float manaRegen);
	void increaseStats();
	void printStats();
};

Player::Player() { }

Player::Player(string name, int amountOfSpells) : Character(name) {
    Spells temp;
	for (int i = 0; i < amountOfSpells; i++)
	    spells.push_back(temp);
}


Weapon Player::getWeapon() const {
    return weapon;
}

Spells Player::getSpells(int index) const {
    return spells[index];
}

string Player::getClass() const {
    return classType;
}

string Player::getGuild() const {
    return guild;
}

int Player::getSpellSize() const {
    return spells.size();
}

int Player::getMaxHealth() const {
    return maxHealth;
}

int Player::getMaxMana() const {
    return maxMana;
}

int Player::getStrength() const {
    return strength;
}

int Player::getDefense() const {
    return defense;
}

int Player::getSpeed() const {
    return speed;
}

int Player::getIntelligence() const {
    return intelligence;
}

float Player::getcurrentHealth() const {
    return currentHealth;
}

float Player::getcurrentMana() const {
    return currentMana;
}

float Player::getManaRegen() const {
    return manaRegen;
}

void Player::setPlayer(string mainLanguage, string race, string sex, string classType,
    string guild, int age, int maxHealth, int maxMana, int strength, int defense,
    int speed, int intelligence, float height, float weight, float currentHealth,
    float currentMana, float manaRegen) {
    // Set Character stats
    this->Character::mainLanguage = mainLanguage;
    this->Character::race = race;
    this->Character::sex = sex;
    this->Character::age = age;
    this->Character::height = height;
    this->Character::weight = weight;
    // Set Player stats
    this->classType = classType;
    this->guild = guild;
    this->maxHealth = maxHealth;
    this->maxMana = maxMana;
    this->strength = strength;
    this->defense = defense;
    this->speed = speed;
    this->intelligence = intelligence;
    this->currentHealth = currentHealth;
    this->currentMana = currentMana;
    this->manaRegen = manaRegen;
}

// Increases x stats with y values
void Player::increaseStats() {
	int amountOfStats = rand()%4 + 1;
	int amountIncrease = 0;
	int increasedStat = 0;
	
	for (int i = 0; i < amountOfStats; i++) {
	    amountIncrease = rand()%25 + 1;
	    increasedStat = rand()%6 + 1;
    	switch(increasedStat) {
        case 1:
            maxHealth += amountIncrease;
            currentHealth = maxHealth;
            break;
        case 2:
            if (maxMana != 0) {
                maxMana += amountIncrease;
                currentMana = maxMana;
                manaRegen += amountIncrease/manaRegen;
            }
            else {
                maxHealth += amountIncrease/2;
                currentHealth = maxHealth;
            }
            break;
        case 3:
            strength += amountIncrease/2;
            break;
        case 4:
            defense += amountIncrease/2;
            break;
        case 5:
            speed += amountIncrease/3;
            break;
        case 6:
            intelligence += amountIncrease/3;
            break;
        }
	}
}

void Player::printStats() {
    
}

/* Enemy */
class Enemy: public Character {
private:
	int maxHealth, strength, defense, speed;
	float currentHealth;

public:
	Enemy(string name, int maxHealth = 100, float currentHealth = 100,
	      int strength = 50, int defense = 50, int speed = 25);
	int attack();
	void takeDamage(int damage);
};

Enemy::Enemy(string name, int maxHealth, float currentHealth, int strength, int defense, int speed) : Character(name) {
	this->maxHealth = maxHealth;
	this->currentHealth = currentHealth;
	this->strength = strength;
	this->defense = defense;
	this->speed = speed;
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

/* NPC */
class Npc: public Character {
public:
	Npc(string name);
	void Dialogue();
};

Npc::Npc(string name) : Character(name) { }

void Npc::Dialogue() {
	int dialogueNumber = rand() % 10;

	if (dialogueNumber == 0)
		cout << "0";

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


/* other */
void clearCin();

void displayMenu(const string menu, Character* = NULL, Character* = NULL, Character* = NULL);

void printCharacter(const Player&);

/* main */
int main() {
	try {
		srand(time(0));
		vector<Player> characters;
		vector<Player> party;
		characters.resize(5);
		party.resize(3);
		int index = 0;
		int list[3];
		char userInput = ' ';

		characters[0] = Player("Feno Beilar", 10);
		characters[1] = Player("Cormo Mistmoon", 0);
		characters[2] = Player("Vorom Riz", 0);
		characters[3] = Player("Erolith Wranxidor", 0);
		characters[4] = Player("Kikrunli Hammerhead", 9);

		for (const Player& key : characters) {
			cout << key.getName() << endl;
		}

		cout << endl << "Which character do what to be your main character? (0-4) : ";
		cin >> index;
		while(!cin || (index < 0 || 4 < index)) {
			clearCin();
			cout << endl << "That is not one of the five integers you can input." << endl;
			cout << "Please enter 0, 1, 2, 3, 4.\nWhat main character do you want? ";
			cin >> index;
		}
		list[0] = index;

		cout << "What do you want you second character to be? ";
		cin >> index;
		while(!cin || (index < 0 || 4 < index)) {
			clearCin();
			cout << endl << "That is not one of the five integers you can input." << endl;
			cout << "Please enter 0, 1, 2, 3, 4.\nWhat other character do you want? ";
			cin >> index;
		}
		list[1] = index;

		cout << "What do you want the third character to be? ";
		cin >> index;
		while(!cin || (index < 0 || 4 < index)) {
			clearCin();
			cout << endl << "That is not one of the five integers you can input." << endl;
			cout << "Please enter 0, 1, 2, 3, 4.\nWhat main character do you want? ";
			cin >> index;
		}
		list[2] = index;

		for (int i = 0; i < 3; i++) {
			switch (list[i]) {
			case 0:
				party[i] = characters[0];
				break;
			case 1:
				party[i] = characters[1];
				break;
			case 2:
				party[i] = characters[2];
				break;
			case 3:
				party[i] = characters[3];
				break;
			case 4:
				party[i] = characters[4];
				break;
			}
		}

        cout << endl << "Your party lead is " << party[0].getName() << " with "
             << party[1].getName() << " and " << party[2].getName() << " being members!" << endl;
        displayMenu("options");
        
		// Loop through menus
		while (party[0].getAlive() == true) {
			cin >> userInput;

			switch (userInput) {
			case 'T':
				displayMenu("teams", &party[0], &party[1], &party[2]);
				break;

			case 'R':
				displayMenu("look");
				break;

			case 'Q':
				cout << "Would you like to print out " << party[0].getName() << "? (Y/N) ";
				cin >> userInput;
				if (userInput == 'Y')
					printCharacter(party[0]);

				return 0;
			}
		}

		cout << party[0].getName() << " died, your team members can no longer work together!" << endl;
		cout << "Would you like to print out " << party[0].getName() << "? (Y/N) ";
		cin >> userInput;
		if (userInput == 'Y')
			printCharacter(party[0]);

		return 0;
	}
	catch (const char* c) {
		cout << "Exepetion caught: " << c << endl;
	}
}

/* other */
void clearCin() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void displayMenu(const string menu, Character *c1, Character *c2, Character *c3) {
	cout << "***************************" << endl;
	if (menu == "options") {
		cout << "(T)  Look at team" << endl;
		cout << "(R)  Look around the room" << endl;
		cout << "(Q)  Quit Game" << endl;
		cout << "What would you like to do? ";
	}
	else if (menu == "teams") {
		cout << "Which character would you like to look at?" << endl;
		cout << "(1)  " << c1->getName() << endl;
		cout << "(2)  " << c2->getName() << endl;
		cout << "(3)  " << c3->getName() << endl;
		cout << "(4)  Back to Option Screen" << endl;
		cout << "What would you like to do? ";
	}
	else if (menu == "look") {

	}
	else {
		cout << "No menu selected..." << endl;
	}
}

void printCharacter(const Player &p) {
	ofstream file(p.getName() + ".txt");
	file.width(10);
	file << left << "Name:" << p.getName() << endl;
	
	file.width(10);
	file << "Status:";
	if (p.getAlive())
		file << "Alive" << endl;
	else
		file << "Dead" << endl;
	
	file.width(10);
    file << "Race:" << p.getRace() << endl;
    file.width(10);
	file << "Sex:" << p.getSex() << endl;
	file.width(10);
	file << "Height:" << p.getHeight() << endl;
	file.width(10);
	file << "Weight:" << p.getWeight() << endl;
	file.width(10);
	file << "Language:" << p.getLanguage() << endl;
	
	
	file.width(10);
	file << endl << "Weapon:" << "\n\t" << p.getWeapon();
	
	file.width(10);
	file << "Spells:" << endl;
	int i = 0;
	for (i; i < p.getSpellSize(); i++) {
	    file << "\t" << p.getSpells(i);
	}
    if (i == 0) {
        file << "\t" <<"None" << endl;
    }
	/*
	file.width(10);
	file << ":" << p. << endl;
    */
	
	file.close();
}
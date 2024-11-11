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

public:
	Spells();
	void setSpell(string type, string attackType = "Melee", int power = 20, float attackRate = .5);
	int getPower();
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

int Spells::getPower() {
	return power;
}

ostream& operator<<(ostream &os, const Spells &s) {
	os << s.type << " is a/an " << s.attackType << " that has " << s.power << " attack powers, and can be cast every " << s.attackRate << " minutes." << endl;
	return os;
}

/* Weapons */
class Weapon {
private:
	string type, attackType;
	int attackPower, defensePower;
	float attackRate;

public:
	Weapon();
	void setWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate);
	int getAttackPower();
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

int Weapon::getAttackPower() {
	return attackPower;
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

	int attack();
	void takeDamage(int damage);

	void setPlayer(string mainLanguage, string race, string sex, string classType,
	               string guild, int age, int maxHealth, int maxMana, int strength,
	               int defense, int speed, int intelligence, float height, float weight,
	               float currentHealth, float currentMana, float manaRegen);
	void setPlayerSpell(int index, string type, string attackType, int power, float attackRate);
	void setPlayerWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate);
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

int Player::attack() {
	int damage = weapon.getAttackPower() + rand()%5;
	return damage;
}

void Player::takeDamage(int damage) {
	currentHealth -= damage;
	if (currentHealth <= 0) {
		maxHealth = 0;
		alive = false;
	}
}

void Player::setPlayer(string mainLanguage, string race, string sex, string classType,
                       string guild, int age, int maxHealth, int maxMana, int strength, int defense,
                       int speed, int intelligence, float height, float weight, float currentHealth,
                       float currentMana, float manaRegen) {
	this->Character::mainLanguage = mainLanguage;
	this->Character::race = race;
	this->Character::sex = sex;
	this->Character::age = age;
	this->Character::height = height;
	this->Character::weight = weight;

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

void Player::setPlayerSpell(int index, string type, string attackType, int power, float attackRate) {
	spells[index].setSpell(type, attackType, power, attackRate);
}

void Player::setPlayerWeapon(string type, string attackType, int attackPower, int defensePower, float attackRate) {
	weapon.setWeapon(type, attackType, attackPower, defensePower, attackRate);
}

// Increases x stats with y values
void Player::increaseStats() {
	int amountOfStats = rand()%4 + 1;
	int amountIncrease = 0;
	int increasedStat = 0;
	cout << name << "\'s stat(s) have increased!" << endl;

	for (int i = 0; i < amountOfStats; i++) {
		amountIncrease = rand()%7 + 1;
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
				manaRegen += amountIncrease/(manaRegen*7);
			}
			else {
				maxHealth += (amountIncrease/2 == 0)? 1 : amountIncrease/2;
				currentHealth = maxHealth;
			}
			break;
		case 3:
			strength += (amountIncrease/2 == 0)? 1 : amountIncrease/2;
			break;
		case 4:
			defense += (amountIncrease/2 == 0)? 1 : amountIncrease/2;
			break;
		case 5:
			speed += (amountIncrease/3 == 0)? 2 : amountIncrease/3;
			break;
		case 6:
			intelligence += (amountIncrease/3 == 0)? 2 : amountIncrease/3;
			break;
		}
	}
}

void Player::printStats() {
	cout << "***************************" << endl;
	cout.width(14);
	cout << left << "Name:" << name << endl;

	cout.width(14);
	cout << "Health:" << currentHealth << "/" << maxHealth << endl;

	if (maxMana != 0)
	{
		cout.width(14);
		cout << "Mana:" << currentMana<< "/" << maxMana << endl;
		cout.width(14);
		cout << "  Regen:" << manaRegen << endl;
	}

	cout.width(14);
	cout << "Strength:" << strength << endl;
	cout.width(14);
	cout << "Defense:" << defense << endl;
	cout.width(14);
	cout << "Speed:" << speed << endl;
	cout.width(14);
	cout << "Intelligence:" << intelligence << endl << endl;

	cout << getWeapon();

	for (int i = 0; i < spells.size(); i++) {
		if (i == 0)
			cout << "Spells:" << endl;
		cout <<"   " << getSpells(i);
	}

}

/* Enemy */
class Enemy: public Character {
private:
	int maxHealth, strength, defense, speed;
	float currentHealth;

public:
	Enemy();
	Enemy(string name);
	int getcurrentHealth();
	int getSpeed();
	int attack();
	void takeDamage(int damage);
};

Enemy::Enemy() { }

Enemy::Enemy(string name) : Character(name) {
	maxHealth = (rand() % 20) + 10;
	currentHealth = maxHealth;
	strength = (rand() % 25) + 25;
	defense = (rand() % 25) + 25;
	speed = (rand() % 10) + 25;
}

int Enemy::getcurrentHealth() {
	return currentHealth;
}

int Enemy::getSpeed() {
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

/* NPC */
class Npc: public Character {
public:
	Npc(string name);
	void dialogue();
};

Npc::Npc(string name) : Character(name) { }

void Npc::dialogue() {
	int dialogueNumber = rand() % 10;

	if (dialogueNumber == 0)
		cout << "The greatest villains are the ones who think they\'re doing the right thing.";

	if (dialogueNumber == 1)
		cout << "If a person stops fighting. They have truly given up...";

	if (dialogueNumber == 2)
		cout << "So good at fitting in, that nobody ever saw them.";

	if (dialogueNumber == 3)
		cout << "There are three types of people. Those who are true to themselves, those who act,\n   and those who are multi-faced.";

	if (dialogueNumber == 4)
		cout << "Just because they refuse to diagnosis doesn\'t mean that the conditions weren\'t\n   there.";

	if (dialogueNumber == 5)
		cout << "There is a difference between being lonely and being alone.";

	if (dialogueNumber == 6)
		cout << "Don\'t apologize if you're going to take it back in the future.";

	if (dialogueNumber == 7)
		cout << "Betrayal never comes from your enemy. It comes from the people you trust most.";

	if (dialogueNumber == 8)
		cout << "Asking illogical people for logic is illogical.";

	if (dialogueNumber == 9)
		cout << "It\'s my opponent, not my enemy.";
}


/* other */
void clearCin();

void displayMenu(const string menu, Character* = NULL, Character* = NULL, Character* = NULL);

void battle(Player*, Player*, Player*);

void printCharacter(const Player&);

/* main */
int main() {
	try {
		srand(time(0));
		Npc antodia("Antodia");
		vector<Player> characters;
		vector<Player> party;
		characters.resize(5);
		party.resize(3);
		int index = 0;
		int list[3];
		char userInput = ' ';

		characters[0] = Player("Feno Beilar", 10);
		characters[0].setPlayer("Common", "High Elf", "Female", "Wizard", "Black Dynasty",
		                        137, 8, 12, 10, 12, 30, 16, 5.83, 140.67, 8, 12, 0.6);
		characters[0].setPlayerWeapon("Darts", "Small Range", 6, 0, 0.6);
		characters[0].setPlayerSpell(1, "Prestidigitation", "Cantrip", 0, 10);
		characters[0].setPlayerSpell(2, "Ray of Frost", "Cantrip", 2, 0);
		characters[0].setPlayerSpell(3, "Shocking Grasp", "Cantrip", 8, 0);
		characters[0].setPlayerSpell(4, "Detect Magic", "Short Range", 0, 0);
		characters[0].setPlayerSpell(5, "Mage Armor", "Melee", 0, 1);
		characters[0].setPlayerSpell(6, "Magic Misslie", "Long Range", 12, 1);
		characters[0].setPlayerSpell(7, "Shield", "Self Spell", 0, 1);
		characters[0].setPlayerSpell(8, "Sleep", "Mid Range", 0, 1);
		characters[0].setPlayerSpell(9, "Thunderwave", "Short Range", 8, 0);

		characters[1] = Player("Cormo Mistmoon", 0);
		characters[1].setPlayer("Common", "Halfling", "Male", "Rogue", "Shadowgarde",
		                        47, 9, 0, 8, 14, 25, 13, 4.42, 85.34, 9, 0, 0);
		characters[1].setPlayerWeapon("Shortbow", "Long Range", 6, 0, 1.4);

		characters[2] = Player("Vorom Riz", 0);
		characters[2].setPlayer("Common", "Human", "Male", "Paladin", "Fiends of Abandonment",
		                        27, 12, 0, 16, 18, 30, 11, 5.5, 117, 12, 0, 0);
		characters[2].setPlayerWeapon("Battleaxe", "Melee", 8, 2, 1.6);

		characters[3] = Player("Erolith Wranxidor", 0);
		characters[3].setPlayer("Common", "Wood Elf", "Male", "Fighter", "Highstars",
		                        95, 12, 0, 13, 14, 35, 10, 6.08, 148.32, 12, 0, 0);
		characters[3].setPlayerWeapon("Greatsword", "Melee", 12, 4, 1);

		characters[4] = Player("Kikrunli Hammerhead", 9);
		characters[4].setPlayer("Common", "Hill Dwarf", "Female", "Cleric", "Black Dynasty",
		                        74, 11, 18, 14, 18, 25, 10, 3.92, 77.42, 11, 18, 1.84);
		characters[4].setPlayerWeapon("Mace", "Small Range", 6, 0, 1.15);
		characters[4].setPlayerSpell(0, "Guidance", "Cantrip", 0, 1);
		characters[4].setPlayerSpell(1, "Light", "Cantrip", 0, 0);
		characters[4].setPlayerSpell(2, "Sacred Flame", "Cantrip", 8, 0);
		characters[4].setPlayerSpell(3, "Bless", "Short Range", 0, 1);
		characters[4].setPlayerSpell(4, "Cure Wounds", "Melee", 0, 0);
		characters[4].setPlayerSpell(5, "Guiding Bolt", "Long Range", 0, 1);
		characters[4].setPlayerSpell(6, "Healing Word", "Mid Range", 0, 0);
		characters[4].setPlayerSpell(7, "Sanctuary", "Short Range", 0, 1);
		characters[4].setPlayerSpell(8, "Shield of Faith", "Mid Range", 0, 10);

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
		     << party[1].getName() << " and " << party[2].getName() << " being members!" << endl << endl;
		cout << "Your team as ented a skill testing dungeon! You are no longer able to use spells\n   unless they do damage or use any items!" << endl;
		displayMenu("options");

		// Loop through menus
		while (party[0].getAlive()) {
			cin >> userInput;

			switch (userInput) {
			case 'T':
				displayMenu("teams", &party[0], &party[1], &party[2]);
				cin >> userInput;
				switch (userInput) {
				case '1':
					party[0].printStats();
					displayMenu("options");
					break;
				case '2':
					party[1].printStats();
					displayMenu("options");
					break;
				case '3':
					party[2].printStats();
					displayMenu("options");
					break;
				case '4':
					displayMenu("options");
					break;
				default :
					displayMenu("options");
				}
				break;

			case 'R':
				displayMenu("look");
				cin >> userInput;
				switch (userInput) {
				case '1':
					battle(&party[0], &party[1], &party[2]);
					if (party[0].getAlive())
						displayMenu("options");
					break;
				case '2':
					cout << endl << "Antodia: \"";
					antodia.dialogue();
					cout << "\"" << endl;
					displayMenu("options");
					break;
				case '3':
					displayMenu("options");
					break;
				default :
					displayMenu(" ");
				}
				break;

			case 'Q':
				cout << "Would you like to print out " << party[0].getName() << "? (Y/N) ";
				cin >> userInput;
				if (userInput == 'Y')
					printCharacter(party[0]);

				return 0;

			default :
				displayMenu(" ");
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
		cout << "There are enemies and Antodia here!" << endl;
		cout << "(1)  Fight the enemies" << endl;
		cout << "(2)  Talk to Antodia" << endl;
		cout << "(3)  Back to Option Screen" << endl;
		cout << "What would you like to do? ";
	}
	else
		throw "The proper menu was not selected!";
}

void battle(Player *p1, Player *p2, Player *p3) {
	vector<Enemy> enemies;
	int amountOfEnemies = (rand() % 5) + 1;
	string names[5] = {"Elf", "Orc", "Human", "Dragonborn", "shapechanging"};
	enemies.resize(amountOfEnemies);
	for (int i = 0; i < amountOfEnemies; i++)
		enemies[i] = Enemy(names[rand()%5]);

	cout << "You entered battle!" << endl;

	enemies[1].takeDamage(p1->attack());

	if (p1->getAlive())
		p1->increaseStats();
	if (p2->getAlive())
		p2->increaseStats();
	if (p3->getAlive())
		p3->increaseStats();
}

void printCharacter(const Player &p) {
	ofstream file(p.getName() + ".txt");
	file.width(14);
	file << left << "Name:" << p.getName() << endl;

	file.width(14);
	file << "Status:";
	if (p.getAlive())
		file << "Alive" << endl;
	else
		file << "Dead" << endl;

	file.width(14);
	file << "Health:" << p.getcurrentHealth() << "/" << p.getMaxHealth() << endl;

	if (p.getMaxMana() != 0)
	{
		file.width(14);
		file << "Mana:" << p.getcurrentMana() << "/" << p.getMaxMana() << endl;
		file.width(14);
		file << "  Regen:" << p.getManaRegen() << endl;
	}

	file.width(14);
	file << "STR:" << p.getStrength() << endl;
	file.width(14);
	file << "DEF:" << p.getDefense() << endl;
	file.width(14);
	file << "SPD:" << p.getSpeed() << endl;
	file.width(14);
	file << "INT:" << p.getIntelligence() << endl << endl;

	file.width(14);
	file << "Age:" << p.getAge() << endl;
	file.width(14);
	file << "Race:" << p.getRace() << endl;
	file.width(14);
	file << "Sex:" << p.getSex() << endl;
	file.width(14);
	file << "Height:" << p.getHeight() << endl;
	file.width(14);
	file << "Weight:" << p.getWeight() << endl;
	file.width(14);
	file << "Language:" << p.getLanguage() << endl << endl;

	file.width(14);
	file << "Class:" << p.getClass() << endl;
	file.width(14);
	file << "Guild:" << p.getGuild() << endl << endl;

	file.width(10);
	file << "Weapon:" << "\n\t" << p.getWeapon();

	for (int i = 0; i < p.getSpellSize(); i++) {
		if (i == 0)
			file << "Spells:" << endl;
		file <<"   " << p.getSpells(i);
	}

	file.close();
}

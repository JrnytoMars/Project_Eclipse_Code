#pragma once
#include <string>
#include <vector>
#include "DamageModifiers.h"

using namespace std;

class Item {
protected:
	string itemName;

	//put your damage types in here. We may express them in a different way later
	const vector<string> damageTypes {
		{"Slice", "Blunt", "Pierce", "Int-Based", "Fai-Based"}
	};

	void slotPosition() {

	}
};

class Gear : public Item {

};

class Weapon : public Gear {
public:
	bool isUnarmed;
	string skill;
	vector<string> itemDamageTypes;

};

class Armor : public Gear {

};

class Sword : public Weapon {

};

class StraightSword : public Sword {
	StraightSword() {
		itemName = "Striaght Sword";
		skill = "Lunging Slash";
		itemDamageTypes = {"Slice"};
	}
};

class Hammer : public Weapon {

};

class Axe : public Weapon {

};

class Spear : public Weapon {

};

class Dagger : public Weapon {

};

//Any of these weapons can be turned into their own class at anytime
class MiscWeapon : public Weapon {

};

class MartialArt : public Weapon {

};

class Bow : public Weapon {

};

class Gun : public Weapon {

};

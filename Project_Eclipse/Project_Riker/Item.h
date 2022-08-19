/* Creator: Marcus Butler.
Most Recent Edit: Marcus, 8/19/22
Pressing Issues (List Any Here):
*/
#pragma once
#include <string>
#include <vector>

using namespace std;

class Item {
protected:
	string itemName;
	string itemDescription;

	//the slot position will be a virtual function. Hoping this makes it easier to code
	void slotPosition() {

	}
};

class Gear : public Item {
protected:
	int gearLevel;
	int maxGearLevel;
	vector<double> itemStats;
	vector<string> itemStatNames;
};

class Weapon : public Gear {
public:
	//put your damage types in here. We may express them in a different way later
	const vector<string> damageTypes {
		{"Slash", "Strike", "Pierce", "Int-Based", "Fai-Based"}
	};

	int levelScaling;
	bool isUnarmed;
	string skill;
	vector<string> itemDamageTypes;
	vector<char> statTiers;

	Weapon() {
		//Not sure if I should have "Weight" as a stat or not
		itemStatNames = { "Physical", "Magic", "Fire", "Ice", "Lightning", "Holy", "Arcane", "Critical", "Weight" };
		maxGearLevel = 10;
		gearLevel = 0;
		levelScaling = 0;
	}

	//will be used for weapon leveling - a compelling equation for leveling still has to be made
	void refinement() {
		int i = 0;
		for (char tier : statTiers) {
			//not sure what method of scaling I should use here
			if (tier != 'F') {
				if (tier == 'S') {
					itemStats[i] += 30;
				}
				itemStats[i] += 20;
			}
			i++;
		}
		levelScaling++;
		if (levelScaling / 5 == 1 || 2) {
			for (char tier : statTiers) {
				if (tier != 'S') {
					if (tier != 'A')
						tier = tier - 1;
					else
						tier = 'S';
				}
			}
		}
	}
};

class Armor : public Gear {
	vector<string> itemDamageResistances;
	Armor() {
		//Not sure if I want to differentiate between Physical and Slash/Strike/Pierce.
		itemStatNames = { "VS Physical", "VS Magic", "VS Fire", "VS Ice", "VS Lightning",
		"VS Holy", "VS Arcane", "Poise", "Weight" };
		maxGearLevel = 5;
	}
};

#pragma region swords
class Sword : public Weapon {
protected:
	Sword() {
		itemDamageTypes = { "Slash" };
	}
};

class StraightSword : public Sword {
	StraightSword() {
		itemName = "Striaght Sword";
		skill = "Lunging Slash";
		itemStats = { 100, 0, 0, 0, 0, 0, 0, 0, 0 };
		statTiers = { 'D', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F' };
	}
};

class ShortSword : public Sword {
	ShortSword() {
		itemName = "Short Sword";
		skill = "Rapid Thrust";
		itemStats = { 80, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		statTiers = { 'D', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F' };
	}
};

class Uchigatana : public Sword {
	Uchigatana() {
		itemName = "Uchigatana";
		skill = "Solid Stance";
		itemStats = { 120, 0, 0, 0, 0, 0, 0, 0, 0 };
		statTiers = { 'C', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F' };
	}
};

class Broadsword : public Sword {
	Broadsword() {

	}
};

#pragma endregion swords


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

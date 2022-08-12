#pragma once
#include "EnemyClass.h"
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>

class Stats {
	public:
		//stat values
		double health, mana, stamina, energy,
			strength, proficiency, intelligence,
			faith, luck;
		//remaining resource stats
		double rHealth, rMana, rStamina;
		//stat levels
		int hpL, mpL, spL, enrL, strL, profL, inteL, faiL, luckL;

		std::vector<double> statVector {
			{health, mana, stamina, energy, strength, proficiency, intelligence, faith, luck}
		};

		std::vector<int> statLevelVector {
			{hpL, mpL, spL, enrL, strL, profL, inteL, faiL, luckL}
		};

		std::vector<std::string> statNames {
			{"hp", "mp", "sp", "enr", "str", "prof", "int", "fai", "luck"}
		};

};

class CharacterStats : public Stats, public Movement {
public:
		
	int level, levelRespec;
	std::vector<std::string> equipmentSlots, inventory;

	//Only gets called when the CharacterStats class is constructed
	CharacterStats() {
		level = 1;
		maxMovementSpeed = 10;
		for (int i = 0; i < statVector.size(); i++) {
			statLevelVector[i] = 1;
			statVector[i] = initialValues(i);
		}
	}

	//sets character stat levels to 1, also used for level respec
	void resetStats() {
		levelRespec = level - 1;
		level = 1;
		for (int i = 0; i < statVector.size(); i++) {
			statLevelVector[i] = 1;
			statVector[i] = initialValues(i);
		}
		/*NOTE: At this point, the player should be able to reassign their levels using a 
		do while loop. The actual respec can't be coded yet, because we aren't working in an engine
		in order to have inputhandlers in the first place.*/
		do {
			level++;
			levelRespec--;
		} while (levelRespec > 0);
	};

	/*NOTE: The values for each position are the base values for the corresponding stat.
	We haven't yet assigned variables to these stats, nor have we determined if they are needed.
	If you wish to create seperate variables for these, then do as you wish.*/
	double initialValues(int pos) {
		//double value;
		// health, mana, stamina
		if (pos == 0) {
			health = 500;
			rHealth = health;
			return health;
		}
		else if (pos == 1) {
			mana = 150;
			rMana = mana;
			return mana;
		}
		else if (pos == 2) {
			stamina = 250;
			rStamina = stamina;
			return stamina;
		}
		// energy, strength, proficiency
		else if (pos == 3) {
			energy = 100;
			return energy;
		}
		else if (pos == 4) {
			strength = 200;
			return strength;
		}
		else if (pos == 5) {
			proficiency = 200;
			return proficiency;
		}
		// intelligence, faith, luck
		else if (pos == 6) {
			intelligence = 200;
			return intelligence;
		}
		else if (pos == 7) {
			faith = 200;
			return faith;
		}
		else if (pos == 8) {
			luck = 100;
			return luck;
		}
		else {
			return 100;
		}

	}

	void levelStats(std::string stat) {
		level++;

		for (int i = 0; i < statVector.size(); i++) {
			if (stat == statNames[i]) {
				statLevelVector[i]++;
				if (statLevelVector[i] > 50) {
					statVector[i] += 20;
				}
				else {
					statVector[i] += statLevelVector[i];
				}
			}
		}
	}
	//Function for assigning values from stat matrices to stat values and levels. Not sure if this will be truly meeded yet
	void statCheck() {
			
	}

};

class CharacterStatPresets {

};

class EnemyStats : public Stats, public Movement {
//stats for specifically enemies
public:
	int prevHits, flasksUsed;
	double aggression, distance, alpha, delta;

	void setStats() {

	}
	//This takes the position of the player character and the enemy character and calculates the distance
	double Distance(std::vector<double> pP, std::vector<double> eP) {
		delta = sqrt(pow(eP[0] - pP[0], 2) + pow(eP[1] - pP[1], 2) + pow(eP[2] - pP[2], 2));
		return delta;
	}
	//Calculates the aggressiveness of the enemy character
	double Aggression() {

		alpha = energy / intelligence;

		/* If the enemy character is a high energy character, then the aggressiveness of that character
		increases as their hp and mana decreases. If the character's proficiency is greater than alpha, then
		no matter how low that characters hp gets, it won't affect the aggression
		*/
		if (alpha > 2) {
			aggression = alpha * ((health + (1 / rHealth)) + (mana + (1 / rMana)) + stamina + energy) / distance;
			return aggression;
		}
		else if (proficiency > alpha) {
			aggression = alpha * (health + mana + stamina + energy) / distance;
			return aggression;
		}
		else {
			aggression = alpha * (rHealth + rMana + stamina + energy) / distance;
			return aggression;
		}

	}

};

class Movement {
	protected:
		/*important for character movement when we can finally use inputhandlers. All of the units of position in
		physics. timeStep will be used for a little calculus later. (We'll probably just use unreal engine's
		physics engine anyway, but I've added these here for if we don't want to.)*/
		double movementSpeed, maxMovementSpeed, acceleration, xCord, yCord, zCord, timeStep;

		std::vector<double> position {
			{xCord, yCord, zCord}
		};

};
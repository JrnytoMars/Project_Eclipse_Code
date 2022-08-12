#pragma once
#include "Stats.h"
#include "Item.h"
#include <string>
#include <vector>

using namespace std;

class DamageModifiers {
	CharacterStats character;
	std::vector<std::string> dependencies;

	double calcDamage(Weapon weapon, std::vector<double> attackerStats, std::vector<double> defenderStats) {
		double damage;
		damage = 0;
		return damage;
	}

	std::vector<std::string> checkDependencies(Weapon weapon) {
		
		return dependencies;
	}
};
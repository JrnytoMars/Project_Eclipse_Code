/* Creator: Marcus Butler.
Most Recent Edit: Marcus, 8/18/22
Pressing Issues (List Any Here):
*/
#pragma once
#include "Stats.h"
#include "Item.h"
#include <string>
#include <vector>

using namespace std;

class DamageModifiers {
protected:
	CharacterStats character;
	std::vector<std::string> dependencies;

	double calcDamage(Weapon weapon, std::vector<double> attackerStats, std::vector<double> defenderStats) {
		int i = 0;
		double damage;
		checkDependencies(weapon);

		//A FAR more interesting form of damage calculation is needed. The loop itself also needs refinement
		for (string dep : dependencies) {
			if (dep == weapon.damageTypes[i]) {
				if (i <= 2) {
					damage = attackerStats[4] + attackerStats[5] - defenderStats[0];
				}
				else {
					damage = attackerStats[6] + attackerStats[7] - defenderStats[1];
				}
			}
			i++;
		}
		return damage;
	}

	void checkDependencies(Weapon weapon) {
		for (string i : weapon.itemDamageTypes)
			dependencies.push_back(i);
	}
};
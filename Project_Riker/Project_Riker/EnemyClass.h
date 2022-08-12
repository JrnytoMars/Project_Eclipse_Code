#pragma once
#include "Stats.h"
#include "AI_Mechanics.h"
#include <vector>

//we want every class, including bosses, to be derived from "Enemy". This is for universal enemy mechanics
class Enemy {
protected:
	/*vectors for the names of each of attack or action.
	NOTE: the entries of the combo matrix will be appended to for every character, 
	using entries left over from the offensive matrix.*/
	std::vector<std::string> offMatrix, defMatrix, idleMatrix, comboMatrix;

	//This will store the equations of ^these matrices, whose values will be used for AI_Mechanics
	std::vector<double> eqnMatrix;

	EnemyStats stats;
	AI_Mechanics mechanics;
	
	//Approach chance equation
	double approachEqn() {
		eqnMatrix.push_back(stats.distance + stats.aggression);
	}
};

class Boss : public Enemy {

};

class Human : public Enemy {

};

class Beast : public Enemy {

};

class Knight : Human {
	Knight() {
		offMatrix = {
			{"L.A. 1", "L.A. 2", "H.A.", "Approach", "Def. State", "Idle State"}
		};
		defMatrix = {
			{"Guard", "Backstep", "Parry", "Off. State", "Idle State"}
		};
		idleMatrix = {
			{"Strafe", "Patrol", "Path", "Off. State", "Def. State"}
		};
		comboMatrix = {
			{"Skill 1", "Skill 2", "Skill 3"}
		};
	}
};

class Inmate : Human {

};

class Dragon : Beast {

};

class Clergyman : Human {

};

class Scholar : Human {

};

class RabidChimera : public Boss {

};
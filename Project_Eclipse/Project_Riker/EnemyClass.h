/* Creator: Marcus Butler.
Most Recent Edit: Marcus, 8/19/22
Pressing Issues (List Any Here):
*/
#pragma once
#include "Stats.h"
#include "AI_Mechanics.h"
#include "Item.h"
#include <vector>
#include <string>

//we want every class, including bosses, to be derived from "Enemy". This is for universal enemy mechanics
class Enemy : public EnemyStats {
protected:
	std::string enemyName;
	/*vectors for the names of each of attack or action.
	NOTE: the entries of the combo vector will be appended to for every character, 
	using entries left over from the offensive vector.*/
	std::vector<std::string> offVector, defVector, idleVector, comboVector;

	//This will store the equations of ^these vectors, whose values will be used for AI_Mechanics
	std::vector<double> eqnVector;

	//Eventually, we will also need gear and weapons in this class as well
	AI_Mechanics mechanics;
	
	//Approach chance equation
	double approachEqn() {
		eqnVector.push_back(distance + aggression);
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
		enemyName = "Exhalted Knight";
		offVector = {
			{"L.A. 1", "L.A. 2", "H.A.", "Approach", "Def. State", "Idle State"}
		};
		defVector = {
			{"Guard", "Backstep", "Parry", "Off. State", "Idle State"}
		};
		idleVector = {
			{"Strafe", "Patrol", "Path", "Off. State", "Def. State"}
		};
		comboVector = {
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

//Second Phases still need to be coded
#pragma region bosses
class RabidChimera : public Boss {
	RabidChimera() {
		enemyName = "Rabid Chimera";
	}
};

class ArcaneNecromancer : public Boss {
	ArcaneNecromancer() {
		enemyName = "Arcane Necromancer";
	}
};

class NecropolisStatues : public Boss {
	NecropolisStatues() {
		enemyName = "Necropolis Statues";
	}
};

class WeepingSpider : public Boss {
	WeepingSpider() {
		//Sorry, I haven't written this in the notebook yet.
		/*Second Phase will be "Eldest Son of the Spider Queen": Name is still pending.
		On entry to the boss arena, the spider queen's children can be seen writhing in her back sac. (See Wolf Spider 
		for example). As lore, it'll be known that spiders in (insert game country name here) slowly consume their parents
		upon birth. As a result, these "spiders", despite holding the same look, turn out to be a bit fleshy, being more mammals 
		than arachnids. Upon the death of the spider queen (Weeping Spider), the eldest son will burst out and fully
		consume her, before slowly turning its head and staring down the MC. Phase 2 then starts.*/
		enemyName = "Weeping Spider";
	}
};

//Name of this boss isn't determined yet. (We could literally just name him Gavin)
class MetalStar : public Boss {
	MetalStar() {
		enemyName = "..., Metal Star";
	}
};

class Melek : public Boss {
	Melek() {
		enemyName = "Melek, The Conscious Parasite";
	}
};

//Rival Boss (Name pending)
class Rose : public Boss {
	Rose() {
		enemyName = "Rose";
	}
};

//Penultimate Boss
class Lovenski : public Boss {
	Lovenski() {
		enemyName = "Lovenski, Harbinger of the End";
	}
};

#pragma region superbosses
class Death : public Boss {
	Death() {
		enemyName = "Death Itself";
	}
};

class Michael : public Boss {
	Michael() {
		enemyName = "Michael, Archangel of Heaven";
	}
};

class Lucifer : public Boss {
	Lucifer() {
		enemyName = "Lucifer, Ruler of Hell";
	}
};

//Final Boss
class IzoAndBakunawa : public Boss {
	IzoAndBakunawa() {
		enemyName = "Izo and Bakunawa, Denizens of the Eclipse";
	}
};
#pragma endregion superbosses
#pragma endregion bosses
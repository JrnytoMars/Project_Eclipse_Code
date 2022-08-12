//#include "AI_Mechanics.h"
#include "Stats.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	CharacterStats character;
	//character.statMatrix[0][0] = character.initialValues(0, 0);
	cout << "Your current level is: " << character.statVector[0] << endl;
	cout << "Your current HP value is: " << character.health << endl;
}



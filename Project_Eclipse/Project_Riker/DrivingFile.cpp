/* Creator: Marcus Butler.
Most Recent Edit: Marcus, 8/18/22
Pressing Issues (List Any Here):
*/
#include "AI_Mechanics.h"
#include "Stats.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	char tier = 'D';
	CharacterStats character;

	cout << "Your tier is: " << tier << endl;
	cout << "Your next tier is: " << static_cast<char>(tier - 1) << endl;
}

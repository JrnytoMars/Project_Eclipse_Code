/* Creator: Marcus Butler.
Most Recent Edit: Marcus, 8/18/22
Pressing Issues (List Any Here):
*/
#pragma once
#include "Stats.h"
#include <math.h>
#include <stdio.h>
#include <vector>
#include <random>
#include <functional>

class AI_Mechanics
{
protected:
	EnemyStats enemy;
	//probability sum, total sum of all probability equations
	double probSum;
	//probability matrices for each enemy state
	std::vector<double> probabilityVector;

	//creates probability distribution then chooses action
	int getAction(std::vector<double> vector) {
		int i = 0;
		int j = 0;
		double n;
		std::vector<double> queue;
		//probability calculation stuff
		std::random_device rand_dev;
		std::mt19937 generator(rand_dev());
		std::uniform_real_distribution<double> distr(0.0, 1.0);

		//calculates the total distribution size by adding each individual value from vector
		for (i = 0; i != vector.size(); i++) {
			probSum += vector[i];
		}
		//creates probability distribution by normalizing the data from the initial vector
		for (i = 0; i != vector.size(); i++) {
			probabilityVector.push_back(vector[i] / probSum);
		}
		//gives the probabilities concrete positions in a queue
		for (j = 0; j < probabilityVector.size(); j++) {
			for (i = j; i >= 0; i--) {
				queue[j] += probabilityVector[i];
			}
		}
		/*NOTE: This is where the important stuff happens. Now that we've taken the probabilities and placed
		them in a queue, we now generate a random real number that we'll check against that queue.
		The position of the first number to be greater than or equal to that random number will be returned.*/
		n = distr(generator);
		for (i = 0; i < queue.size(); i++) {
			if (n <= queue[i]) {
				return i;
			}
			else {
				return -1;
			}
		}
	}
	//will be used to map an AI's path to the player character when aggroed.
	void mapPath() {
		if (checkMapping() == true) {

		}
	}
	//will be used to check if a path can be mapped from the enemy character to the player
	bool checkMapping() {

	}
};

#pragma once
#include <math.h>
#include <stdio.h>
#include <vector>
#include <random>
#include <functional>
#include "Stats.h"

class AI_Mechanics
{
	protected:
		EnemyStats enemy;
		//probability sum, total sum of all probability equations
		double probSum;
		//probability matrices for each enemy state
		std::vector<double> probabilityMatrix;

		//creates probability distribution then chooses action
		int getAction(std::vector<double> matrix) {
			int i = 0;
			int j = 0;
			double n;
			std::vector<double> queue;
			//probability calculation stuff
			std::random_device rand_dev;
			std::mt19937 generator(rand_dev());
			std::uniform_real_distribution<double> distr(0.0, 1.0);

			//calculates the total distribution size by adding each individual value from matrix
			for (i = 0; i != matrix.size(); i++) {
				probSum += matrix[i];
			}
			//creates probability distribution by normalizing the data from the initial matrix
			for (i = 0; i != matrix.size(); i++) {
				probabilityMatrix.push_back(matrix[i] / probSum);
			}
			//gives the probabilities concrete positions in a queue
			for (j = 0; j < probabilityMatrix.size(); j++) {
				for (i = j; i >= 0; i--) {
					queue[j] += probabilityMatrix[i];
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
		double mapPath() {
			checkMapping();
		}
		//will be used to check if a path can be mapped from the enemy character to the player
		bool checkMapping() {

		}
};

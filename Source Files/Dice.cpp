/*
 * Dice.cpp
 *
 *  Created on: Jun 17, 2020
 *      Author: Olivier
 */

#include "Dice.h"			//include dice header file
#include <cstdlib>			//include this for random number generating function (rand, srand)
#include <ctime>			//include time function (for seeding)


Dice::Dice() {
	// TODO Auto-generated constructor stub

}


Dice::~Dice() {
	// TODO Auto-generated destructor stub
}

int Dice::roll() {

	srand((int)time(0));	//'seed' parameter is time function to ensure an ever-changing sequence of random numbers
	return (rand() % 6) + 1; //randomize rolls between 1 and six
}


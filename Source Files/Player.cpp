/*
 * Player.cpp
 *
 *  Created on: Jun 17, 2020
 *      Author: Olivier
 */

#include "Player.h"		//reference the player header file
#include "Dice.h"		//reference the dice header file
#include <iostream>		//include input and output stream

using namespace std;	//use standard namespace to avoid writing std:: all the time


Player::Player() {
	// TODO Auto-generated constructor stub
	playerName = "";
	numChips = 0;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

//function definition
string Player::getName() {

	return playerName;
}

//function definition
void Player::setName(string s) {

	playerName = s; //input player's name

}

//function definition
int Player::getChips() {

	return numChips;
}

//function definition
void Player::setChips(int i) {

	numChips = i; //input number of chips
}

//function definition
int Player::setNumChips() {

	int moveChips = 0;	//declare variable to hold result of return value
	Dice turn;			//create object of Dice class

	//switch statement to perform different operations based on result of 'rolling' variable
	switch(turn.roll()) {

		case 1:

			cout << "Rolling a 'L' caused you to lose a chip and pass it to the player on the left.\n";
			moveChips = -1;

			break;

		case 2:

			cout << "Rolling a 'C' caused you to lose a chip and remove it from play.\n";
			moveChips = 10;

			break;

		case 3:

			cout << "Rolling a 'R' caused you to lose a chip and pass it to the player on the right.\n";
			moveChips = 1;

			break;

		case 4:

			cout << "No action is taken for this die.\n";

			break;

		case 5:

			cout << "No action is taken for this die.\n";

			break;

		case 6:

			cout << "No action is taken for this die.\n";

			break;
	}



	return moveChips; //return the result based on which value turn.roll() generates

}

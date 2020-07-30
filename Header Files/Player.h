/*
 * Player.h
 *
 *  Created on: Jun 17, 2020
 *      Author: Olivier
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>

using namespace std;

class Player {

public:

	Player();
	virtual ~Player();

	string playerName;
	int numChips;

	string getName();
	void setName(string);
	int getChips();
	void setChips(int);
    int setNumChips();	//function to distribute and move chips accordingly
};

#endif /* PLAYER_H_ */

/*
 * main.cpp
 *
 *  Created on: Jun 17, 2020
 *      Author: Olivier Dejoie
 *
 *      This is my implementation of the LCR dice game. Overall, I'd say that this was a great learning
 *      experience for me. I had used object oriented principles before, but this project was definitely
 *      the most advanced in terms of how it is organized. The bulk of my bugs that I ran into were focused
 *      on the logic responsible for passing chips to the correct player and limiting the amount of times a
 *      player gets to roll based on their chip count. I reached out to my professor and I was given guidance
 *      on how I needed to call the PLAYER constructor and then input those players into the array
 *      responsible for handling the correct turn rotation. After some dedicated execution testing combined with
 *      the advice my professor offered, I was able to fix these bugs.
 *
 *	Edited on: Jul 28, 2020
 *		Editor: Olivier Dejoie
 *
 */

//include statements
#include "Dice.h"
#include "Player.h"
#include <iostream>		//input + output stream
#include <fstream>		//file stream
#include <limits>		//numeric limits

using namespace std;			//standard namespace to avoid writing std:: every time

Player p;						//creating class 'Player' object

void printInstructions();		//function declaration


//main function
int main() {

   printInstructions();			//call the print instructions method


	int numPlayers;		//initialize variable for user input number of players
	cout << "\n" << "To begin, please enter the number of players participating: ";
	cin >> numPlayers;	//accept user input

	//while loop that forces the user to input a minimum of three players
	while (numPlayers < 3) {

		cout << "\nAs per the instructions outlined above, LCR requires a minimum of 3 players.\n";
		cout << "\n" << "Please enter the amount of players participating: ";
		cin >> numPlayers;

	}

	//Creates array of type "Player" objects. Each player has their own name and chip count as defined in the class
	Player* participants = new Player[numPlayers];
	//holds user input names of participants
	string name;

	//for loop to iterate through participant list and input each players name as well as give each player 3 chips
	for(int i = 0; i < numPlayers; i++) {

		cout << "Please input each players name one at a time: ";
		cin >> name;
		p.setName(name);
		p.setChips(3);
		participants[i] = p;
	}

	cout << "\nThe game will now begin!\n";		//Introduction to start playing


	bool win = false;		//boolean to determine if winner has been selected
	int moveChips;			//declare to hold result of Player::setNumChips function outlined in player class


	//while a winner hasn't been declared, the below sequence will continue
	while(win != true) {

		//for loop to give each player a turn in the correct sequence
		for(int x = 0; x < numPlayers; x++) {

			cout << "\n" << "NEXT UP:\n";

			//if somebody lost all of their chips, the below statement will print and the following player's turn commences
			if(participants[x].getChips() == 0) {

				cout << "\n" << participants[x].playerName << ", You're still participating, but your turn will be skipped this round.\n";
				x++; //skip to next player

			}

			//show the current player their amount of chips and prompts them to roll the dice
			cout << "\n" << participants[x].getName() << ", you have " << participants[x].getChips() << " remaining chips.\n";
			cout << participants[x].getName() << ", to proceed, press the return key to roll the dice." << endl;

			//tells program to ignore everything until the delimiter 'return' key or, more specifically '\n' has been input
			cin.ignore(numeric_limits<streamsize>::max(),'\n');

			int n = 1; //variable to hold count for amount of times a player has rolled

			//for loop to determine how many rolls a player gets per turn
			for(int r = 0; r < participants[x].getChips() && r < 3; r++) {


				//tells program to ignore everything until the delimiter 'return' key or, more specifically '\n' has been input
				cin.ignore(numeric_limits<streamsize>::max(),'\n');

				//prints the current roll number to the console to keep track of how many times a player has rolled
				cout << "***** Roll # "<< n << " executed *****\n";

				//initialize to the output of the setNumChips function in player class
				//and determines how the chips will be passes around
				moveChips = p.setNumChips();


				//if moveChips returns a -1, the following code will enact
				if(moveChips == -1) {

					//This code subracts a chip from the current player
					participants[x].numChips--;

					//******** SPECIAL CASE: if the player at position '0' has to pass to the left, then:
					if(x == 0) {

						//the player at the end of the array will gain a chip
						participants[numPlayers - 1].numChips++;

					}
					//Otherwise, the other players can simply subtract one from their positions in the array and add a chip
					else  {

						participants[x - 1].numChips++;
					}
				}

				//if moveChips returns a 10, the following code will enact
				else if(moveChips == 10) {

					//subtract a chip from the current player
					participants[x].numChips--;
				}

				//if moveChips returns a 1, the following code will enact
				else if(moveChips == 1) {

					//subtract a chip from current player
					participants[x].numChips--;

					//******** SPECIAL CASE: if the player at position 'sizeof(array - 1)' has to pass to the right, then:
					if(x == numPlayers - 1) {

						//the player at position '0' will gain a chip
						participants[0].numChips++;
					}
					//otherwise, the other players can simply add one from their positions in the array and add a chip
					else {

						participants[x + 1].numChips++;
					}
				}

				//print statement that shows the current player how many chips they have after their roll/turn
				cout << "\n" << participants[x].getName() << ", you have " << participants[x].getChips() << " remaining chips.\n";

				//iterate n (the variable that holds the roll count)
				n++;

				//variable to determine whether one player controls all of the chips on the table or not
				int total = 0;

				//loop to iterate through the list of players and add everyones' current chip count after every roll
				for(int y = 0; y < numPlayers; y++) {

					total = participants[y].getChips() + total;		//update total
				}

				//loop to iterate through list of players and determine whether a winner will be declared
				for(int b = 0; b < numPlayers; b++){

					//if any player has all of the available chips, then:
					if(participants[b].getChips() - total == 0) {

						//Print celebratory statement
						cout << participants[b].getName() << ", you control all of the remaining chips!\n";
						cout << "YOU WIN!!!!!";
						win = true;			//change winner variable to true
						return 0;
					}
				}
			}
		}
	}

	return 0;
}


void printInstructions() {

    string lineOfText;				//This represents each line
	ifstream txtfile ("LCR_Instructions.txt");	//creates input file stream object linked to .txt file
	if (txtfile.is_open())			//opens file
	{
	  while ( getline (txtfile,lineOfText) )	//reads the .txt file line by line
	  {
	    cout << lineOfText << '\n';			//as it reads each line, it also prints the line to the console.
	  }
	  txtfile.close();						//finally close the file by flushing the buffer
	}

	else {

	  cout << "An error has occurred.";		//if file isn't opened this will print

	}

}



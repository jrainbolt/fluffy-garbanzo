// Maze1.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int LIMIT = 100;
/*Global data structures*/
int maze[LIMIT] =
{ 5,5,5,5,5,5,5,5,5,5,
 5,0,0,0,5,5,5,5,5,5,
 5,5,0,5,5,5,0,0,5,5,
 5,5,0,5,5,5,0,5,5,5,
 5,5,0,0,0,0,0,5,5,5,
 5,5,0,5,0,5,5,5,5,5,
 5,5,0,5,0,0,0,5,5,5,
 5,5,5,5,0,5,0,5,5,5,
 5,5,0,0,0,5,0,0,0,5,
 5,5,5,5,5,5,5,5,5,5 };

const int start = 11;
const int finish = 88;
const int moves[4] = { -1, -10, 1, 10 }; // Left, up, right, down.
int cameFrom[LIMIT]; //used to track where we came from

void displayMaze(int current, int maze[])
{
	cout << endl;
	cout << "At: " << current << " " << endl;			//Display square numbers as we go

	cout << "      0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "      -------------------" << endl;
	for (int i = 0; i < LIMIT; i++) {
		//Display the row number at the beginning of each line
		if (i % 10 == 0) {
			cout << setw(2) << i << " |";
		}
		cout << maze[i] << " ";

		//Display the newline character at the end of each line
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}
}

//Make a move, from the perspective of square whose index is in current
void makeMove(int current) {
	int i, nextMove;

	//Display the initial maze
	displayMaze(current, maze);

	while (current != finish) {
		//Try all four moves.
		//Note that the initial assignment for i is only done the first time.
		for (i = maze[current]; i < 4; i++) {
			nextMove = current + moves[i];
			maze[current] = i; // Advance value in this square to keep track of progess
			if ((maze[nextMove] != 5) && (nextMove != cameFrom[current])) {

				//Make a move to a new location
				cameFrom[nextMove] = current;
				current = nextMove;

				// Display the maze values, reflecting this new move
				displayMaze(current, maze);
				//Check to see if we've reached the finnish
				if (current == finish) {
					cout << " *** Reached finish! ***" << endl;
					return;
				}

				//Reset loop counter, since it doesn't automatically reevaluate.
				//Also subtract 1, since it will autoincrement when repeating loop.
				i = maze[current] - 1;
			}
		} //end for(i=0...

		//If value at current square == 4, then all possible moves were exhausted,
		//so go back to previous location.
		if (maze[current] == 3) {
			current = cameFrom[current];
			//Advance the value at that previous location, if there are still moves left,
			//so that when we backtrack we don't try the same previous move again.
			if (maze[current] < 4) {
				maze[current]++;
			}
		}
	}
} //end makeMove()

void displaySolution(int current) {
	cout << "Solution is: " << endl;
	cout << current << " ";
	do {
		current = current + moves[maze[current]];
		cout << current << " ";
	} while (current != finish);
}

int main()
{
	cout << "Search Path Traversed: \n" << endl;
	makeMove(start);
	displaySolution(start);
    return 0;
} //end main()


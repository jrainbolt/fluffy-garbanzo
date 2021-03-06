// Maze1.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define LIMIT 100
/*Global date structures*/
const int maze[LIMIT] =
{ 1,1,1,1,1,1,1,1,1,1,
 1,0,0,0,1,1,1,1,1,1,
 1,1,0,1,1,1,0,0,1,1,
 1,1,0,1,1,1,0,1,1,1,
 1,1,0,0,0,0,0,1,1,1,
 1,1,0,1,0,1,1,1,1,1,
 1,1,0,0,0,0,0,1,1,1,
 1,1,1,1,0,1,0,1,1,1,
 1,1,0,0,0,1,0,0,0,1,
 1,1,1,1,1,1,1,1,1,1 };

const int start = 11;
const int finish = 88;

//Make a move, from the perspective of square whose index is in current
void makeMove(int current) {
	static int moves[4] = { -1, - 10, 1, 10 }; //Left, up, right, down.
	int i, nextMove;

	cout << current << " ";			//display square numbers as we go
	if (current == finish) {
		cout << " *** Reached finish! ***" << endl;
	}

	for (i = 0; i < 4; i++) { //Try all four moves
		nextMove = current + moves[i];
		if (maze[nextMove] != 1) {
			makeMove(nextMove);
		}
	} // endu for(i=0...
} //end makeMove()

void displaySolution(int current) {}


int main()
{
	cout << "Search Path Traversed: \n" << endl;
	makeMove(start);
	displaySolution(finish);
    return 0;
}//end main


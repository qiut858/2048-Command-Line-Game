#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Board {
	int gameboard[16];
	int score;
	int largest_number;
	public:
	Board();
	void clearBoard();
	bool isFilled();
	bool makeMove(string);
	void randMove();
	void printScore();
	void printBoard();
	bool noMovesLeft();
	bool win();
};

#endif

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "Board.h"

using namespace std;

Board::Board(): score(0) {
	for(int i = 0; i < 16; i++) {
		gameboard[i] = 0;
	}
}

void Board::clearBoard() {
	for(int i = 0; i < 16; i++) {
		gameboard[i] = 0;
	}
}

bool Board::isFilled() {
	bool filled = 1;
	for(int i = 0; i < 16; i++) {
		if (gameboard[i] == 0) {
			filled = 0;
		    break;
		}
	}
	return filled;
}

bool Board::makeMove(string input) {
	bool changed = 0;
	int previous_board[16];
	for (int i = 0; i < 16; i++) {
		previous_board[i] = gameboard[i];
	}

	if (input == "u") {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				int this_space = gameboard[i + (j * 4)];
				int next_space = gameboard[i + ((j + 1) * 4)];
				if ((j == 2) && (this_space == 0) && 
					(gameboard[i + ((j - 1) * 4)] == 0) && 
					((gameboard[i + ((j - 2) * 4)] == 0) || (gameboard[i + ((j - 2) * 4)] == next_space))) {
					gameboard[i + ((j - 2) * 4)] += next_space;
				    gameboard[i + ((j - 1) * 4)] = 0;
					gameboard[i + (j * 4)] = 0;
					gameboard[i + ((j + 1) * 4)] = 0;
					if (gameboard[i + ((j - 2) * 4)] != next_space) {
						score += next_space * 2;
					}
				} else if (((j == 2) || (j == 1)) && 
						   (this_space == 0) && 
					       ((gameboard[i + ((j - 1) * 4)] == 0) || (gameboard[i + ((j - 1) * 4)] == next_space))) {
					gameboard[i + ((j - 1) * 4)] += next_space;
					gameboard[i + (j * 4)] = 0;
					gameboard[i + ((j + 1) * 4)] = 0;
					if (gameboard[i + ((j - 1) * 4)] != next_space) {
						score += next_space * 2;
					}
				} else if (this_space == 0) {
					gameboard[i + (j * 4)] = next_space;
					gameboard[i + ((j + 1) * 4)] = 0;
				} else if (this_space == next_space) {
					gameboard[i + (j * 4)] *= 2;
					gameboard[i + ((j + 1) * 4)] = 0;
					score += next_space * 2;
				}
			}
		}
	} else if (input == "d") {
		for (int i = 0; i < 4; i++) {
			for (int j = 3; j > 0; j--) {
				int this_space = gameboard[i + (j * 4)];
				int next_space = gameboard[i + ((j - 1) * 4)];
				if ((j == 1) && (this_space == 0) && 
					(gameboard[i + ((j + 1) * 4)] == 0) && 
					((gameboard[i + ((j + 2) * 4)] == 0) || (gameboard[i + ((j + 2) * 4)] == next_space))) {
					gameboard[i + ((j + 2) * 4)] += next_space;
				    gameboard[i + ((j + 1) * 4)] = 0;
					gameboard[i + (j * 4)] = 0;
					gameboard[i + ((j - 1) * 4)] = 0;
					if (gameboard[i + ((j + 2) * 4)] != next_space) {
						score += next_space * 2;
					}
				} else if (((j == 2) || (j == 1)) && 
					       (this_space == 0) && 
					       ((gameboard[i + ((j + 1) * 4)] == 0) || (gameboard[i + ((j + 1) * 4)] == next_space))) {
					gameboard[i + ((j + 1) * 4)] += next_space;
					gameboard[i + (j * 4)] = 0;
					gameboard[i + ((j - 1) * 4)] = 0;
					if (gameboard[i + ((j + 1) * 4)] != next_space) {
						score += next_space * 2;
					}
				} else if (this_space == 0) {
					gameboard[i + (j * 4)] = next_space;
					gameboard[i + ((j - 1) * 4)] = 0;
				} else if (this_space == next_space) {
					gameboard[i + (j * 4)] *= 2;
					gameboard[i + ((j - 1) * 4)] = 0;
					score += next_space * 2;
				}
			}
		}
	} else if (input == "l") {
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 3; i++) {
				int this_space = gameboard[i + (j * 4)];
				int next_space = gameboard[i + 1 + (j * 4)];
				if ((i == 2) && (this_space == 0) && 
					(gameboard[i - 1 + (j * 4)] == 0) && 
					((gameboard[i - 2 + (j * 4)] == 0) || (gameboard[i - 2 + (j * 4)] == next_space))) {
					gameboard[i - 2 + (j * 4)] += next_space;
				    gameboard[i - 1 + (j * 4)] = 0;
					gameboard[i + (j * 4)] = 0;
					gameboard[i + 1 + (j * 4)] = 0;
					if (gameboard[i - 2 + (j * 4)] != next_space) {
						score += next_space * 2;
					}
				} else if (((i == 2) || (i == 1)) && 
					       (this_space == 0) && 
					       ((gameboard[i - 1 + (j * 4)] == 0) || (gameboard[i - 1 + (j * 4)] == next_space))) {
					gameboard[i - 1 + (j * 4)] += next_space;
					gameboard[i + (j * 4)] = 0;
					gameboard[i + 1 + (j * 4)] = 0;
					if (gameboard[i - 1 + (j * 4)] != next_space) {
						score += next_space * 2;
					}
				} else if (this_space == 0) {
					gameboard[i + (j * 4)] = next_space;
					gameboard[i + 1 + (j * 4)] = 0;
				} else if (this_space == next_space) {
					gameboard[i + (j * 4)] *= 2;
					gameboard[i + 1 + (j * 4)] = 0;
					score += next_space * 2;
				}
			}
		}
	} else {
		for (int j = 0; j < 4; j++) {
			for (int i = 3; i > 0; i--) {
				int this_space = gameboard[i + (j * 4)];
				int next_space = gameboard[i - 1 + (j * 4)];
				if ((i == 1) && (this_space == 0) && 
					(gameboard[i + 1 + (j * 4)] == 0) && 
					((gameboard[i + 2 + (j * 4)] == 0) || (gameboard[i + 2 + (j * 4)] == next_space))) {
					gameboard[i + 2 + (j * 4)] += next_space;
				    gameboard[i + 1 + (j * 4)] = 0;
					gameboard[i + (j * 4)] = 0;
					gameboard[i - 1 + (j * 4)] = 0;
					if (gameboard[i + 2 + (j * 4)] != next_space) {
						score += next_space * 2;
					}
				} else if (((i == 2) || (i == 1)) && 
					       (this_space == 0) && 
					       ((gameboard[i + 1 + (j * 4)] == 0) || (gameboard[i + 1 + (j * 4)] == next_space))) {
					gameboard[i + 1 + (j * 4)] += next_space;
					gameboard[i + (j * 4)] = 0;
					gameboard[i - 1 + (j * 4)] = 0;
					if (gameboard[i + 1 + (j * 4)] != next_space) {
						score += next_space * 2;
					}
				} else if (this_space == 0) {
					gameboard[i + (j * 4)] = next_space;
					gameboard[i - 1 + (j * 4)] = 0;
				} else if (this_space == next_space) {
					gameboard[i + (j * 4)] *= 2;
					gameboard[i - 1 + (j * 4)] = 0;
					score += next_space * 2;
				}
			}
		}
	}
	for (int i = 0; i < 16; i++) {
		if (previous_board[i] != gameboard[i]) {
			changed = 1;
			break;
		}
	}
	return changed;
}

void Board::randMove() {
	srand (time(NULL));
	int random_number = (rand() % 2 + 1) * 2;
	int list_empty[16];
	int num_empty = 0;
	for(int i = 0; i < 16; i++) {
		if (gameboard[i] == 0) {
			list_empty[num_empty] = i;
			num_empty++;
		}
	}
	int random_space = list_empty[rand() % num_empty];
	gameboard[random_space] = random_number;
}

void Board::printScore() {
	cout << "Your Score: " << score << endl;
}

void Board::printBoard() {
	//int numb_digits = digits(largest_number);
	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int j = 0; j < 4; j++) {
			/*if (numb_digits <= 4) { */
				cout << setw(4) << gameboard[i * 4 + j];
				cout << "|";
			/*} else {
				cout << setw(numb_digits) << gameboard[i * 4 + j];
				cout << "|";
			} */
		}
		cout << "" << endl;
	}
}
bool Board::noMovesLeft() {
	Board sampleup;
	Board sampledown;
	Board sampleleft;
	Board sampleright;
	
	for (int i = 0; i < 16; i++) {
		sampleup.gameboard[i] = gameboard[i];
		sampledown.gameboard[i] = gameboard[i];
		sampleleft.gameboard[i] = gameboard[i];
		sampleright.gameboard[i] = gameboard[i];
	}

	sampleup.makeMove("u");
	sampledown.makeMove("d");
	sampleleft.makeMove("l");
	sampleright.makeMove("r");

	bool same = 1;
	for (int i = 0; i < 16; i++) {
		if ((sampleup.gameboard[i] != gameboard[i]) ||
			(sampledown.gameboard[i] != gameboard[i]) ||
			(sampleleft.gameboard[i] != gameboard[i]) ||
			(sampleright.gameboard[i] != gameboard[i])) {
			same = 0;
			break;
		}
	}
	return same;
}

bool Board::win() {
	bool win = 0;
	for(int i = 0; i < 16; i++) {
		if (gameboard[i] == 2048) {
			win = 1;
		    break;
		}
	}
	return win;
}

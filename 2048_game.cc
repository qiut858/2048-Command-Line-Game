#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include "Board.h"

using namespace std;

int main() {

	Board board1;
	bool game_over = 0;
	board1.randMove();

	while (!(game_over)) {
		system("clear");
		cout << "2048 Puzzle Copy" << endl;
		cout << "Developed by Tom Qiu" << endl;
		cout << endl;
		board1.printScore();

		board1.printBoard();
		string input;
		for(;;) {
			cout << "Your move: (u, d, r, l)" << endl;
			cin >> input;
			if (cin.eof()) {
				return 1;
			} else if (input == "quit") {
				system("clear");
				cout << "Thanks for playing!" << endl;
				return 1;
			} else if (input == "New") {
				cout << "New Game" << endl;
				break;
			} else if ((input != "u") && (input != "d") && (input != "r") && (input != "l")) {
				cout << input << " is not a valid move. Please try agan" << endl;
			} else {
				break;
			}
		}
		if (input == "New") {
			system("clear");
			board1.clearBoard();
			board1.randMove();
			continue;
		}
		if ((board1.makeMove(input)) && (board1.isFilled() == 0)) {
			board1.randMove();
		}
		if (board1.win()) {
			system("clear");
			cout << "2048 Puzzle Copy" << endl;
			cout << "Developed by Tom Qiu" << endl;
			cout << endl;
			board1.printScore();
			board1.printBoard();
			cout << "Congratulations!" << endl;
			cout << "You have won the game." << endl;
			break;
		}
		if (board1.noMovesLeft()) {
			system("clear");
			cout << "2048 Puzzle Copy" << endl;
			cout << "Developed by Tom Qiu" << endl;
			cout << endl;
			board1.printScore();
			board1.printBoard();
			cout << "GAME OVER" << endl;
			game_over = 1;
			continue;
		}
	}
	cout << "Thanks for playing!" << endl;
	return 1;
}


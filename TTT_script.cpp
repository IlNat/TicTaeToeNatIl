#include <iostream>
using std::cout;

char board[3][3];
enum { EMPTY = ' ', CROSS = 'X', ZERO = 'O' };

void print(const char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		cout << ' ' << board[i][0];
		for (int j = 1; j < 3; j++) {
			cout << " | " << board[i][j];
		}
		cout << '\n';
		if (i == 2) {
			break;
		}
		for (int j = 0; j < 3; j++) {
			cout << "---" << ((j == 2) ? '\n' : '+');
		}
	}
}

bool is_full(const char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == EMPTY) {
				return false;
			}
		}
	}
	return true;
}
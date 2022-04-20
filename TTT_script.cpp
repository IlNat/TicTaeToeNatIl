#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "TTT_lib.h"
using std::cout;
using std::cin;

char board[3][3];
enum { EMPTY = ' ', CROSS = 'X', ZERO = 'O' };

char player_char;
char computer_char;

bool is_player_move; //  ������� ��� ������.

void init() {
	setlocale(LC_ALL, "russian");
	srand(time(nullptr));

	do {
		cout << "�������� ���� ����� [X | O]: ";
		cin >> player_char;
		player_char = toupper(player_char); // 'x' -> 'X'
	} while (player_char != 'X' && player_char != 'O');

	bool is_player_move = player_char == 'O';

	computer_char = (player_char == 'X' ? 'O' : 'X');

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = EMPTY;
		}
	}
}
bool is_full() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == EMPTY) {
				return false;
			}
		}
	}
	return true;
}

bool is_game_over() {
	char winner = get_winner();
	bool board_is_full = is_full();
	if (get_winner() != EMPTY) {
		cout << "���������� " << winner << " !\n";
	}
	else if (board_is_full) {
		cout << "�����!\n";
	}
	return is_full();
}

void make_player_move() {
	int row, col;
	do {
		cout << "������� ���������� x: [1; 3] y: [1; 3]: ";
		cin >> col >> row;
		col--;
		row--;
	} while (col < 0 || col > 2 || row < 0 || row > 2 || board [row][col] != EMPTY);

	board[row][col] = player_char;
}

void make_computer_move() {
	// ��� ����������.
	int fstcord;
	int scdcord{};
	 do {
		fstcord = rand() % 3;
		scdcord = rand() % 3;
	 } while (board[fstcord][scdcord] != player_char);
	board[fstcord][scdcord] = computer_char;
}



void make_next_move() {
	if (is_player_move) {
		make_computer_move();
		is_player_move = false;
	}
	else {
		make_computer_move();
		is_player_move = true;
	}
	print();
}

void print() {
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

char get_winner() {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return board[i][0];
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
			return board[0][i];
		}
	}
	if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
		return board[0][0];
	}
	if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
		return board[0][2];
	}
	return EMPTY;
}


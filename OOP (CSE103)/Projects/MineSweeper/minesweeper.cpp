#include "minesweeper.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cassert>


using namespace std;


void minesweeper(string commands, string output) {
	ofstream out(output);
	ifstream in(commands);
	string str1;
	string boardname;


	if (in.is_open()) {
		getline(in, str1);
		
		if (str1.substr(0, 4) == "load") {
			boardname = str1.substr(5);
			
		}
	}

	_load_(output, commands, boardname);
	in.close();
	out.close();
}


void _load_(string output, string commands, string boardname) {
	
	char board[8][8];
	bool touchedboard[8][8];
	bool Gameover = false;

	ofstream out;
	ifstream in;

	string str1;
	string loadboard;

	out.open(output);
	in.open(commands);

	in >> loadboard;
	getline(in, str1);
	
	
	if (loadboard == "load") {
		boardname = str1.substr(1);
		showboard(board, boardname);
		initTouched(touchedboard);
		
	}
	
	cout << "Command: load " << boardname << endl;
	
	string select_coordinate;
	int x = 0;
	int y = 0;
	int max_touch = 54;
	for (int test = 0; test < max_touch; test++) {
		if (!in) {
			break;
		}
		else {
			in >> select_coordinate;
			in >> x;
			in >> y;
			//cout << select_coordinate << endl;
			if (select_coordinate == "touch") {
				_touch_(touchedboard, x, y);
				cout << "Command: touch " << x << " " << y << endl;
				if (board[x - 1][y - 1] =='*') {
					Gameover = true;
					break;
				}
			}
			else if (select_coordinate == "display") {
				cout << "Command: " << loadboard << " " << boardname << endl;
				cout << "Command: " << select_coordinate << endl;
			}
		}
	}
	_display_(out, board, touchedboard, Gameover);
	in.close();
	out.close();
}
void showboard(char board[][8], string file) {
	ifstream test_board;
	test_board.open(file);
	char project_board;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			test_board >> project_board;
			board[i][j] = project_board;
		}
	}
}

void initTouched(bool touchedboard[][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			touchedboard[i][j] = false;
		}
	}

}

void _display_(ofstream& out, char board[][8], bool touchedboard[][8], bool Gameover) {
	int finalboard[8][8];
	int count_bomb = 0;
	int touch_times = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			finalboard[i][j] = 0;
			if (touchedboard[i][j] == true) {
				touch_times++;
			}

		}
	}
	if (Gameover != false) {
		if (touch_times != 0) {
			cout << "Game Over" << endl;
			cout << "~~~~~~~~~" << endl;
			cout << "Final Board" << endl;

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (touchedboard[i][j] == false ) {
						if (board[i][j] == '.') {
							cout << '.';
						}
						else if (board[i][j] == '*') {
							cout << '@';
						}
					}
					else if (touchedboard[i][j] == true) {
						if (board[i][j] == '*') {
							cout << "*";
						}
						else if (board[i][j] == '.') {
							for (int m = i - 1; m <= i + 1; m++) {
								for (int n = j - 1; n <= j + 1; n++) {
									if (m + 1 == 0 || m - 8 == 0 || n + 1 == 0 || n - 8 == 0) {
										continue;
									}
									else if (board[m][n] == '*') {
										count_bomb++;
									}
								}
							}
							cout << count_bomb;
							count_bomb = 0;
						}
						
					}
				}
				cout << endl;
			}
		}
	}
	else {
		if (touch_times != 0) {
			cout << "Game Over" << endl;
			cout << "~~~~~~~~~" << endl;
			cout << "Final Board" << endl;

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (touchedboard[i][j] == false) {
						if (board[i][j] == '.') {
							cout << '.';
						}
						else if (board[i][j] == '*' ) {
							cout << '@';
						}
					}
					else if (touchedboard[i][j] == true) {
						if (board[i][j] == '*') {
							cout << '*';
						}
						else if (board[i][j] == '.') {
							for (int m = i - 1; m <= i + 1; m++) {
								for (int n = j - 1; n <= j + 1; n++) {
									if (m + 1 == 0 || m - 8 == 0 || n + 1 == 0 || n - 8 == 0) {
										continue;
									}
									else if (board[m][n] == '*') {
										count_bomb++;
									}
								}
							}
							cout << count_bomb;
							count_bomb = 0;
						}

					}	
				}
				cout << endl;
			}
		}

		else {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					cout << ".";
				}
				cout << endl;
			}
			cout << "Game Over" << endl;
			cout << "~~~~~~~~~" << endl;
			cout << "Final Board" << endl;

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (board[i][j] == '.') {
						cout << '.';
					}
					else if (board[i][j] == '*') {
						cout << '@';
					}
				}
				cout << endl;
			}
		}
	}
	cout << endl;
	cout << "Spaces touched " << touch_times << endl;
}


void _touch_(bool board[][8], int x, int y) {
	board[x - 1][y - 1] = true;
}


int main() {
	cout << "Testing minesweeper" << endl;
	minesweeper(".\\test1commands.txt", "test1_output_mine.txt");
	minesweeper(".\\test2commands.txt", "test2_output_mine.txt");
	minesweeper(".\\test3commands.txt", "test3_output_mine.txt");
	minesweeper(".\\test4commands.txt", "test4_output_mine.txt");
	minesweeper(".\\test5commands.txt", "test5_output_mine.txt");
	minesweeper(".\\test6commands.txt", "test6_output_mine.txt");
	minesweeper(".\\test7commands.txt", "test7_output_mine.txt");
	minesweeper(".\\test8commands.txt", "test8_output_mine.txt");
	minesweeper(".\\test9commands.txt", "test9_output_mine.txt");
	minesweeper(".\\test10commands.txt", "test10_output_mine.txt");

	return 0;
}

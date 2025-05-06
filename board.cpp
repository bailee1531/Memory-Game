// board.cpp
// Implements the functions for the Board class
#include <iostream>
#include "board.h"

// Default constructor. Initializes the board to a 2d booleant vector of false elements
// boardSize is still the default at this point
Board::Board() : board(boardSize, std::vector<bool>(boardSize, false)) {
}

// Returns the size that is set during instantiation of derived class Difficulty
int Board::getSize() {
	return boardSize;
}

// Updates the board vector to be the size set during instantiation of derived class Difficulty
void Board::updateSize() {
	board.resize(boardSize);
	for (auto& i : board) {
		i.resize(boardSize);
	}
}

// Updates the board element to be true
// int row: index of row
// int col: index of column
void Board::updateBoard(int row, int col) {
	// resets the board to be all false first
	resetBoard();	// this makes it so only one number is shown at a time

	board[row][col] = true;

	calculatedNum = calcNum(row, col);	// calculates the number to be displayed
	displayNums.push_back(calculatedNum);	// puts the number in the displayNums vector
}

// Resets the board vector so all elements are false
void Board::resetBoard() {
	board.assign(boardSize, std::vector<bool>(boardSize, false));
}

// Calculates the number at the passed index
// int row: index of row
// int col: index of column
int Board::calcNum(int row, int col) {
	return (row * boardSize) + col + 1;
}

// Prints the current board
// bool boardState: boolean from enum in main
	// true displays the board with chosen number
	// false displays the board with all X elements
void Board::printBoard(bool boardState) {
	std::cout << "\033[2J\033[1;1H";	// clears the screen so only the current board is shown

	if (boardState) {
		for (int i = 0; i < board.size(); i++) {	// rows
			for (int j = 0; j < board[i].size(); j++) {	//columns
				if (board[i][j]) {
					std::cout << calculatedNum << "\t";	// calculated right before printBoard is called
				}
				else {
					std::cout << "X" << "\t";	// print X if element is still false
				}
			}
			std::cout << std::endl;
		}
	}
	else {	// don't printed calculated num 
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				std::cout << "X" << "\t";	// shows a fully empty board in between each number
			}
			std::cout << std::endl;
		}
	}
}

// Checks the user input against the current vector of ints for the round
// vector<int> userGuess: tokenized ints from user input
bool Board::checkGuess(std::vector<int> userGuess) {
	bool guessResult = false;	// init to false
	if (displayNums == userGuess) {
		guessResult = true;	// flip if true
	}
	// clear the vector of current round numbers
	// previous numbers are appended again each round instead of keeping track of previous rounds
	// allows for duplicates within the same game
	displayNums.clear();	
	return (guessResult);
}

// Destructor
Board::~Board() {

}
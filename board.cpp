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

void Board::updateBoard(int row, int col) {
	resetBoard();
	board[row][col] = true;
	calculatedNum = calcNum(row, col);
	displayNums.push_back(calculatedNum);
}

void Board::resetBoard() {
	board.assign(boardSize, std::vector<bool>(boardSize, false));
}

int Board::calcNum(int row, int col) {
	return (row * boardSize) + col + 1;
}

// Prints the current board
void Board::printBoard(bool boardState) {
	std::cout << "\033[2J\033[1;1H";

	if (boardState) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j]) {
					std::cout << calculatedNum << "\t";
				}
				else {
					std::cout << "X" << "\t";
				}
			}
			std::cout << std::endl;
		}
	}
	else {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				std::cout << "X" << "\t";
			}
			std::cout << std::endl;
		}
	}
}

bool Board::checkGuess(std::vector<int> userGuess) {
	bool guessResult = false;
	if (displayNums == userGuess) {
		guessResult = true;
	}
	displayNums.clear();
	return (guessResult);
}

// Destructor
Board::~Board() {

}
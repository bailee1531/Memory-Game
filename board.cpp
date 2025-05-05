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
void Board::updateBoard() {
	board.resize(boardSize);
	for (auto& i : board) {
		i.resize(boardSize);
	}
}

// Prints the current board
void Board::printBoard() {
	updateBoard();
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Destructor
Board::~Board() {

}
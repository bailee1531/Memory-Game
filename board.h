// board.h
// Defines the parent board class
#pragma once
#include <vector>

class Board {
public:
	Board();
	~Board();
	void printBoard();

protected:
	int boardSize = 2;
	int depth = 1;
	std::vector<std::vector<bool>> board;
	int getSize();
	void updateBoard();
};
// board.h
// Defines the parent board class
#pragma once
#include <vector>

class Board {
public:
	Board();
	~Board();
	int getSize();
	void printBoard(bool state);
	void updateBoard(int row, int col);
	bool checkGuess(std::vector<int> guesses);

protected:
	int boardSize = 2;
	int depth = 1;
	int calculatedNum = 0;
	std::vector<std::vector<bool>> board;
	std::vector<int> displayNums;
	void updateSize();
	void resetBoard();
	int calcNum(int rowIndex, int colIndex);
};
// main.cpp
// Instantiates derived class object and handles user interaction
// Description to be added later
#include <iostream>
#include "difficulty.h"

int main() {
	int diffSelection = 0;

	std::cout << "Welcome to the memory game. Select difficulty." << std::endl;
	std::cout << "1. Easy\n2. Medium\n3. Hard" << std::endl;
	std::cin >> diffSelection;

	Difficulty gameBoard(diffSelection);

	std::cout << "Game Mode: " << gameBoard.getDiff() << std::endl;

	gameBoard.printBoard();

	return 0;
}
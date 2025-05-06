// main.cpp
// Instantiates derived class object and handles user interaction
// Description to be added later
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <utility>
#include <sstream>
#include "difficulty.h"

enum Board_State {
	emptyBoard = false, filledBoard = true
};

int main() {
	int diffSelection = 0;
	int inputNumInt = 0;
	std::string inputNums, individualNums;
	std::vector<int> userNums;
	std::vector<std::pair<int, int>> previousRowsCols;

	srand(time(NULL));

	std::cout << "Welcome to the memory game. Select difficulty." << std::endl;
	std::cout << "1. Easy\n2. Medium\n3. Hard" << std::endl;
	std::cin >> diffSelection;

	Difficulty gameBoard(diffSelection);

	std::cout << "Game Mode: " << gameBoard.getDiff() << std::endl;
	int gameRounds = gameBoard.getRounds();
	int randRow = rand() % gameBoard.getSize();
	int randCol = rand() % gameBoard.getSize();

	while (gameRounds > 0) {
		gameBoard.printBoard(emptyBoard);

		for (auto i : previousRowsCols) {
			gameBoard.updateBoard(i.first, i.second);
			gameBoard.printBoard(filledBoard);
			Sleep(gameBoard.getTime());
			gameBoard.printBoard(emptyBoard);
		}

		gameBoard.updateBoard(randRow, randCol);

		gameBoard.printBoard(filledBoard);
		Sleep(gameBoard.getTime());
		gameBoard.printBoard(emptyBoard);

		std::cout << "Enter the pattern" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, inputNums);
		std::stringstream allNums(inputNums);

		while (allNums >> individualNums) {
			inputNumInt = atoi(individualNums.c_str());
			userNums.push_back(inputNumInt);
		}

		if (gameBoard.checkGuess(userNums) && gameRounds > 1) {
			std::cout << "Correct! Moving on to the next round." << std::endl;
			previousRowsCols.push_back(std::make_pair(randRow, randCol));
			randRow = rand() % gameBoard.getSize();
			randCol = rand() % gameBoard.getSize();
			gameRounds--;
			Sleep(5000);
		}
		else if (gameBoard.checkGuess(userNums) && gameRounds <= 1) {
			std::cout << "Correct! You have completed the game." << std::endl;
			exit(0);
		}
		else {
			std::cout << "Incorrect. Try again." << std::endl;
			Sleep(5000);
		}
	}

	return 0;
}
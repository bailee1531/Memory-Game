// main.cpp
// Instantiates derived class object and handles user interaction
// This memory game displays numbers one by one, then prompts the user to 
// enter the numbers in the correct order. Number of rounds and speed is determined
// by the difficulty the user selects
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <utility>
#include <sstream>
#include "difficulty.h"

// For clarity when passing boolean to printBoard()
enum Board_State {
	emptyBoard = false, filledBoard = true
};

int main() {
	int diffSelection = 0;	// difficulty selection
	int inputNumInt = 0;	// used as a temp for conversion from string to int
	bool roundResult = false;	// holds boolean result for each round instead of checking twice per round
	std::string inputNums, individualNums;	// strings for tokenizing user input and converting to ints
	std::vector<int> userNums;	// holds user inputs to be compared with vector of correct answer
	std::vector<std::pair<int, int>> previousRowsCols;	// ordered pair of indices for previously displayed numbers

	srand(time(NULL));	// generates different numbers each time the program is run

	std::cout << "Welcome to the memory game. Select difficulty." << std::endl;
	std::cout << "1. Easy\n2. Medium\n3. Hard" << std::endl;
	std::cin >> diffSelection;

	Difficulty gameBoard(diffSelection);	// instantiates object of derived class

	std::cin.ignore();	// need to clear \n before using getline and tokenizing input

	std::cout << "Game Mode: " << gameBoard.getDiff() << std::endl;
	int gameRounds = gameBoard.getRounds();

	// initial random indices
	int randRow = rand() % gameBoard.getSize();	
	int randCol = rand() % gameBoard.getSize();

	while (gameRounds > 0) {
		gameBoard.printBoard(emptyBoard);
		userNums.clear();	// users input entire sequence every time, so clear the previous input

		for (auto i : previousRowsCols) {	// iterate through previously displayed nums
			gameBoard.updateBoard(i.first, i.second);	// i.first is row index, i.second is column index
			gameBoard.printBoard(filledBoard);	// print the board with the numbers displayed
			Sleep(gameBoard.getTime());	// pause for time based on difficulty
			gameBoard.printBoard(emptyBoard);	// print the board without any numbers displayed
		}

		gameBoard.updateBoard(randRow, randCol);	// new indices for current round

		gameBoard.printBoard(filledBoard);
		Sleep(gameBoard.getTime());
		gameBoard.printBoard(emptyBoard);

		std::cout << "Enter the pattern" << std::endl;
		std::getline(std::cin, inputNums);	// gets entire input as a string
		std::stringstream allNums(inputNums);	// stores the input into a stringstream for tokenization

		// each number is separated by a space and stored in individualNums
		while (allNums >> individualNums) {
			inputNumInt = atoi(individualNums.c_str());	// convert current number to an int
			userNums.push_back(inputNumInt);	// store int in vector for comparison later
		}

		// gets the result of comparing the user input vector with the vector of the correct numbers
		roundResult = gameBoard.checkGuess(userNums);

		// only generates new row and column indices if the user guess was correct and there are more rounds remaining
		// if user guess was correct and there are no more rounds, exit the game
		// otherwise, display the same number again and do not decrease the number of rounds
		if (roundResult && gameRounds > 1) {
			std::cout << "Correct! Moving on to the next round." << std::endl;

			// next round will display the current number immediately before displaying the new number
			previousRowsCols.push_back(std::make_pair(randRow, randCol));	// adds the current pair of indices to the vector of previous indices
			randRow = rand() % gameBoard.getSize();	// generates a new row index
			randCol = rand() % gameBoard.getSize();	// generates a new column index
			gameRounds--;	// decrease the number of rounds
			Sleep(5000);	// wait 5 seconds between rounds
		}
		else if (roundResult && gameRounds <= 1) {
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
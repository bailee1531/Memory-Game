// difficulty.cpp
// Implements the functions for the Difficulty class
#include "difficulty.h"

// Default constructor
// Sets the board size and board difficulty when instantiated
Difficulty::Difficulty(int userSelection) {
	switch (userSelection) {
	case 1:
		diffLevel = "Easy";
		boardSize = 2;	// easy board is 2x2
		displayTime = 3500;
		rounds = 3;
		break;
	case 2:
		diffLevel = "Medium";
		boardSize = 4;	// medium board is 4x4
		displayTime = 2500;
		rounds = 5;
		break;
	case 3:
		diffLevel = "Hard";
		boardSize = 8;	// hard board is 8x8
		displayTime = 1000;
		rounds = 7;
		break;
	default:
		diffLevel = "Easy";
		boardSize = 2;	// default is the easy board
		displayTime = 3500;
		rounds = 3;
		break;
	}
	updateSize();
}

// Returns the difficulty level set during instantiation
std::string Difficulty::getDiff() {
	return diffLevel;
}

int Difficulty::getTime() {
	return displayTime;
}

int Difficulty::getRounds() {
	return rounds;
}

// Destructor
Difficulty::~Difficulty() {

}
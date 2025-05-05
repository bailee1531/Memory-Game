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
		break;
	case 2:
		diffLevel = "Medium";
		boardSize = 4;	// medium board is 4x4
		break;
	case 3:
		diffLevel = "Hard";
		boardSize = 8;	// hard board is 8x8
		break;
	default:
		diffLevel = "Easy";
		boardSize = 2;	// default is the easy board
		break;
	}
}

// Returns the difficulty level set during instantiation
std::string Difficulty::getDiff() {
	return diffLevel;
}

// Destructor
Difficulty::~Difficulty() {

}
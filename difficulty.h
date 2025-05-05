// difficulty.h
// Defines the derived class Difficulty
#pragma once
#include <string>
#include "board.h"

class Difficulty : public Board {
public:
	Difficulty(int selection);
	std::string getDiff();
	~Difficulty();

protected:
	std::string diffLevel = "Easy";
};
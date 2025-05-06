// difficulty.h
// Defines the derived class Difficulty
#pragma once
#include <string>
#include "board.h"

class Difficulty : public Board {
public:
	Difficulty(int selection);
	std::string getDiff();
	int getTime();
	int getRounds();
	~Difficulty();

protected:
	std::string diffLevel = "Easy";
	int displayTime = 2.5;
	int rounds = 3;
};
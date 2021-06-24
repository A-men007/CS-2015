#include "Player.h"
#include "Guess.h"
#include <iostream>
using namespace std;
#pragma once
//human subclass
class Human : public Player {

private:
	string name;
	int score;
public:

	Human(string);

	inline const string getName() {
		return name;
	}

	Guess getGuess() const;
};
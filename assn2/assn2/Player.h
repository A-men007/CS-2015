//Keeps track of score
#pragma once
#include <string>

class Player {

private:
	int score;
public:

	Player(int);

	inline const int getScore() {
		return score;
	}

	Player& operator--();

	~Player() {};
};
#pragma once
#include <cstdlib>
#include <ctime>

class Guess
{
private:
	//R,P,S
	char guess;
public:
	Guess();
	Guess(char);
	Guess(int);
	inline char GetGuess() {
		return guess;
	}
	int compare(const Guess &other) const;
	~Guess();
};


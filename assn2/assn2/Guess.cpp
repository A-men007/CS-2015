#include "Guess.h"
#include <iostream>
using namespace std;

//default constructor
Guess::Guess() {
	//srand fn with time  
	//time() returns a time_t which is probably a 64-bit integer.
	//srand() wants an unsigned int which is probably a 32 - bit integer. 
	srand((unsigned int)time(0));
	int random = rand() % 3;
	*this = Guess::Guess(random);
}

Guess::Guess(char c) {
	if ((c == 'R') || (c == 'r')) {
		guess = 'R';
	} 
	else if ((c == 'P') || (c == 'p')) {
		guess = 'P';
	}
	else if ((c == 'S') || (c == 's')) {
		guess = 'S';
	}
}

Guess::Guess(int d) {
	if (d == 0) {
		guess = 'R';
	} else if (d == 1) {
		guess = 'P';
	} else if (d == 2){
		guess = 'S';
	}
}


int Guess::compare(const Guess & other) const {
	if (this->guess == other.guess) {
		return 0;
	}
	else if (this->guess > other.guess) {
		//special case to allow S to beat P
		while (!((this->guess == 'P')&&(other.guess == 'S'))) {
			return +1;
		}
		return -1;
	}
	else {
		//special case to allow S to beat P
		while (!((this->guess == 'S') && (other.guess == 'P'))) {
			return -1;
		}
		return +1;
	}
}

Guess::~Guess(){

}

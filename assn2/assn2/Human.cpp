#include "Human.h"

//constructor
Human::Human(string nm) : Player(3) {
	name = nm;
}

Guess Human::getGuess() const {
	char g;
	cout << "Enter (R,P,S): " << endl;
	cin >>g;
	return Guess(g);
}
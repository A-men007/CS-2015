#include "Computer.h"

Computer::Computer() : Player(5){
}

Guess Computer::getGuess() const {
	return Guess();
}

Computer::~Computer()
{
}

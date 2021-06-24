#include "Player.h"

Player::Player(int nscore) {
	score = nscore;
}

Player& Player::operator--() {
	--score;
	return *this;
}

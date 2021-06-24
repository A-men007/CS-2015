#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <cassert>

class Character {
private:
	char c;
	int keyToInt() { assert(c >= 'a'&&c <= 'z'); return c - 'a'; }
public:
	Character(char ch = 'a') :c(ch) {}
	inline char getChar() const { return c; }
	void encrypt(Character key);
	void decrypt(Character key);
};

//These functions would normally appear in the Character.cpp file
//Only placed here for lab convenience

void Character::encrypt(Character key) {
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) {
		int ci = (c >= 'a'&&c <= 'z') ? c - 'a' : c - 'A';
		ci += key.keyToInt(); //ki==0-25
		if (ci > 25) ci -= 26;
		c = ci + ((c >= 'a'&&c <= 'z') ? 'a' : 'A');
	}
}

void Character::decrypt(Character key) {
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) {
		int ci = (c >= 'a'&&c <= 'z') ? c - 'a' : c - 'A';
		ci -= key.keyToInt(); //ki==0-25
		if (ci < 0) ci += 26;
		c = ci + ((c >= 'a'&&c <= 'z') ? 'a' : 'A');
	}
}

#endif /* CHARACTER_H_ */
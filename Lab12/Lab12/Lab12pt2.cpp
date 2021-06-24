#include <iostream>
#include "LinkedList.h"
#include "Character.h"
using namespace std;

int main(int argc, char *argv[]) {

	Queue<Character> message, key;
	int k = 0;
	
	while (argv[2][k] != NULL) {

		message.enqueue(argv[2][k]);
		k++;
	}
	k = 0;
	while (argv[3][k] != NULL) {
		key.enqueue(argv[3][k]);
		k++;
	}
	int sz = message.getSize();
	for (unsigned i = 0; i < sz; i++) {
		if (argv[1][0] == 'D') {
			Character some(message.dequeue());
			some.decrypt(key.dequeue());
			message.enqueue(some.getChar());
		}
		else {
			Character some(message.dequeue());
			some.encrypt(key.dequeue());
			message.enqueue(some.getChar());
		}

	}
	for (unsigned i = 0; i < sz; i++) {
		Character some = message.dequeue();
		cout << some.getChar();
	}
	cout << endl;
	char c;
	cin >> c;
}
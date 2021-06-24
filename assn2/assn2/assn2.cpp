#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include <string>
#include <iostream>
using namespace std;


int main(int argc,char* argv[]) {

	cout << "Enter a name: " << endl;
	string name;
	cin >> name;
	//human obj;
	Human h1(name);
	//comuter obj
	Computer c1;
	cout << "starting score:\n" << name << ": " << h1.getScore() << " Computer:" << c1.getScore() << endl;

	while ((h1.getScore()>0)&&(c1.getScore()>0)) {
		//Guess obj to store each guess value
		Guess H(h1.getGuess());
		Guess C = c1.getGuess();
		cout << name << ": " << H.GetGuess() << " Computer:" << C.GetGuess() << endl;
		//perform compare function in Guess class
		int Compare = H.compare(C);

		if (Compare == +1) {
			h1.operator--();
			cout << name << ": " << h1.getScore() << " Computer:" << c1.getScore() << endl;
		}
		else if (Compare == -1) {
			c1.operator--();
			cout << name << ": " << h1.getScore() << " Computer:" << c1.getScore() << endl;
		}
		else {
			cout << name << ": " << h1.getScore() << " Computer:" << c1.getScore() << endl;
		}
		
	}
	//final winner display
	if (h1.getScore() == 0) {
		cout << name << " WON!!!" << endl;
	}
	else {
		cout << "The computer WON!!!" << endl;
	}

	system("PAUSE");
}
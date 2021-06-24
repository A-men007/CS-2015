#include <iostream>
#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
#include "Fish.h"
using namespace std;

int main(int argc, char *argv[]) {
	Dog dog("Leo");
	string s = dog;
	cout <<"type conversion operator: "<< s << endl;
	dog.speak();
	Cat cat("Speedy");
	string f = cat;
	cout << f << endl;
	cat.speak();
	Fish fish("Sam");
	string d = fish;
	cout << d << endl;
	fish.speak();
	system("PAUSE");
}

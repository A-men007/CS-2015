#include <iostream>
using namespace std;

class Animal {
public:
	int id;
	int getid() { id = 1; return id; }
	//able to overide the differ derived fns 
	virtual void speak() { cout << "Animal" << endl; }
	//function doesn't work for the general class now
	//virtual void speak() = 0;
};

class Fish : public Animal {
public:
	int getid() { id = 2; return id; }
};

class Dog : public Animal {
public:

	void speak() { cout << "Dog" << endl; }
};

int main(int argc, char *argv[]) {
	Dog a;
	a.speak();
	Fish f;
	Animal *pa;
	Fish *pf;
	//setting the animal to the animal address....
	pa = &a;
	//overide compiler by making it believe the animal will be a fish
	//pf = (Fish *)pa;
	
	//compiler cant use speak function b/c a & is changed
	a.speak();
	f.speak();
	pa->speak();
	//pf->speak();
	system("PAUSE");
}
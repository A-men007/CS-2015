#include "Cat.h"

Cat::Cat(string name): Pet(name){
}

void Cat::speak() {
	cout << "Meow!" << endl;
}

Cat::~Cat()
{
}

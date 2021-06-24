#include "Dog.h"
Dog::Dog(string name): Pet(name){

}
//override func.
void Dog::speak() {
	Pet::speak();
	//cout << "Woof!" << endl;
}
Dog::~Dog()
{
}

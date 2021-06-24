#include "Pet.h"

Pet::Pet(string nm){
	name = nm;
}

void Pet::speak(){
	cout << "Hello" << endl;
}

Pet::operator std::string() const {
	return name;
}
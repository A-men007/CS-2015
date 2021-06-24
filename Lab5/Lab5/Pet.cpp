#include "Pet.h"
#include <iostream>
using namespace std;
int Pet::number_pets = 0;


Pet::Pet(const char *nm){
	//10.
	name = nullptr;
	setName(nm);
	number_pets++;
	cout << "Constructor called" << endl;
}
//parameter is looking for a address of a pet object
Pet::Pet(const Pet&src) {
	name = nullptr;
	setName(src.name); 
	number_pets++;
	cout << "Copy constructor" << endl;
}

Pet::Pet(Pet &&obj) {
	name = obj.name;
	obj.name = nullptr;
	number_pets++;
	cout << "Move Constructor " << endl;
}

void Pet::setName(const char *nm) {
	//delete previous pet name
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
	if (nm == nullptr) {
		name = 0;
		return;
	}
	//set a counter variable to 0
	int sz = 0;
	//check if char is filled
	while (nm[sz] != 0) {
		//add up the total size
		sz++;
	}
	//allocate name to size of sz
	name = new char[sz + 1];
	//perform cpy
	for (int i = 0; i < sz; i++) {
		name[i] = nm[i];
	}
	name[sz] = '\0';//terminate new char array with '\0'
}

int Pet::getNameLength() const {
	int sz = 0;
	while (name[sz] != 0) {
		sz++;
	}
	return sz;
}

Pet::~Pet()
{
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
	number_pets--;
	cout << "Destructor" << endl;
}

Pet Pet::operator=(const Pet&rhs) {
	if (rhs.name == name) return *this;
	setName(rhs.name);
	return *this;
}

Pet Pet::operator+(const Pet &rhs) {
	Pet con;
	int sz1 = this->getNameLength();
	int sz2 = rhs.getNameLength()+1;
	con.name = new char[sz1 + sz2];
	for (int i = 0; i < sz1; i++) {
		con.name[i] = this->name[i];
	}
	for (int i = 0; i < sz2; i++) {
		con.name[i] = rhs.name[i];
	}
	return con;
}

ostream& operator<<(ostream& os, const Pet& obj) {
	os << obj.name;
	return os;
}
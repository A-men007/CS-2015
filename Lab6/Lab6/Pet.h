#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pet {
private:
	string name;

public:
	Pet(string);
	string getName() { return name;}
	void speak();
	operator std::string() const;
};
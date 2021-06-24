#pragma once
#include "Pet.h"
class Dog : public Pet {
public:
	//constructor
	Dog(string name);
	void speak();
	~Dog();
};


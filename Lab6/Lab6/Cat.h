#pragma once
#include "Pet.h"
class Cat : public Pet {
public:
	Cat(string name);
	void speak();
	~Cat();
};


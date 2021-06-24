#pragma once
#include <iostream>
using namespace std;
class Pet
{
private:
	//5. create pet name 
	char* name = nullptr;
	static int number_pets;
	//8. counts num of letters in name
	int getNameLength() const;
public:

	//6. create get inline function and rtn num pets
	static int getNumber() {
		return number_pets;
	};

	//7. name getter func. rturn static char*
	const char* getName() {
		return name;
	};

	//10. modified default constructor
	Pet(const char *nm = nullptr);

	//11. cpy constructor
	Pet(const Pet&src);

	//12. mve constructor
	Pet(Pet &&obj);

	void setName(const char *nm);

	~Pet();
	//14
	Pet operator=(const Pet&rhs);
	//15
	Pet operator+(const Pet &rhs);
	friend ostream& operator<<(ostream& os, const Pet&obj);
};

ostream& operator<<(ostream& os, const Pet& obj);

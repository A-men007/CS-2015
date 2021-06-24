#include <iostream>
#include "Pet.h"
using namespace std;

int main(int argc, char *argv[]) {
	Pet p1("aman"), p2("bobby");
	cout << p1 << "\n" << p2 << endl;

	Pet p3 = p1;

	cout << p3 << endl;
	
	Pet p4 = p3 + p2;
	cout << p4 << endl;

	cout << "There are currently: " << Pet::getNumber() << " pets existing." << endl;
	
	system("PAUSE");
}
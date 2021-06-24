#include <iostream>
#include "Bag.h"
#include "BagAnySame.h"
#include "BagAnyDifferent.h"
using namespace std;

//template function
template <class Item>
Item getRandom(Item x, Item y) {
	return x;
}

int main(int argc, char *argv[]) {
	int a = 4;
	double b = 2.50;
	Bag A(a,b);
	BagAnySame<int> C(2,2);
	BagAnySame<float> B(2.2,2.3);
	BagAnyDifferent<int, double> D(5,12.45);

	cout << "Bag object contains\nint: " << A.getObj1() << "\ndouble: " << A.getObj2() << endl;

	cout << "Bag template object contains\nint: " << C.getObj1() << "\ndouble: " << B.getObj2() << endl;

	cout << "Bag 2nd template object contains\nint: " << D.getObj1() << "\ndouble: " << D.getObj2() << endl;

	cout <<"The item returned is: "<< getRandom('A', 'B') << endl;

	system("PAUSE");
}
#include <iostream>
#include "Vector.h"
#include "Point.h"
#include "Polygon.h"
using namespace std;

void print(Vector<int> *pntr) {
	int howbig = pntr->size();

	cout << "the size of the vector is: " << howbig << endl;
	cout << "the elements are: ";
	for (int x = 0; x < howbig; x++) {
		//how to print vector pointer
		cout << pntr->at(x) << " ";
	}
	cout << endl;
}

void print(Vector<double> &pntrr) {
	cout << "the size of the vector is: " << pntrr.size() << endl;
	cout << "the elements are: ";
	for (unsigned x = 0; x < pntrr.size(); x++) {
		cout << pntrr.at(x) << " ";
		}
	cout << endl;
}

int main(int argc, char *argv[]) {
	//step 9
	Vector<int> V;

	V.push_back(1);
	V.push_back(2);
	V.push_back(3);
	//can use V.push_back(1);
	//step 10
	Vector<double> myVec(4);
	myVec[0] = 1.01;
	myVec[1] = 3.90;
	myVec[2] = 17.00;
	myVec[3] = 20.00;
	print(&V);
	print(myVec);
	//step 14. object with initalization
	Point mypoint(1.5,2.5);
	//call print function
	mypoint.print();
	Point p1(10.5, 20.5);
	Point p2(100.5, 200.5);
	Point p3(1000.5, 2000.5);

	
	Polygon myPoly;
	myPoly.addPoint(mypoint);
	myPoly.addPoint(p1);
	myPoly.addPoint(p2);
	myPoly.addPoint(p3);

	myPoly.Print();

	cout << endl;

	system("PAUSE");
}
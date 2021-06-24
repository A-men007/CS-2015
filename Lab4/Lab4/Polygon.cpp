#include "Polygon.h"
#include <iostream>
#include "Point.h"
using namespace std;

Polygon::Polygon()
{
	
}
//16.
inline void addPoint(Point pt);

void Polygon::Print() {
	cout << endl;
	cout << "Polygon: " << Points.size();
	for (unsigned int x = 0; x < Points.size(); x++) {
		cout << endl;
		//PRINT FUNCTION
		Points[x].print();
	}
}

Polygon::~Polygon()
{
}


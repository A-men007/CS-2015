#include "Point.h"
#include <iostream> 
using namespace std;

Point::Point()
{
}
//step 11.
Point::Point(double a, double b) {
	x = a;
	y = b;
}
//step 13.
void Point::print() {
	cout << "{" << x << "," << y << "}";
}
Point::~Point()
{
}

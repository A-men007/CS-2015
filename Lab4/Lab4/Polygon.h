#pragma once
#include "Point.h"
#include "Vector.h"
using namespace std;
class Polygon
{
public:
	Polygon();

	void inline addPoint(Point pt) {
		//16.
		Points.push_back(pt);
	}
	//17
	void Print();

	~Polygon();

private:
	//15
	Vector<Point> Points;
};


#include "Drawing.h"
#include <iostream>
#include <vector>
using namespace std;

class DrawObject {
private:
	//colour member
	COLOUR Colour;

protected:
	//vector container
	vector<COORD> coord;
public:
	///contructor
	DrawObject(COLOUR c) {
		Colour = c;
	}
	COLOUR getColour() {
		return Colour;
	}
	virtual void draw(Drawing &) = 0;

};

class Point : public DrawObject{
public:
	//cnstrctr which accepts a COLOUR and a COORD for the pt
	Point(COORD b, COLOUR c) : DrawObject(c){
		//stores coordinate
		coord.push_back(b);
	}

	void draw(Drawing &A) {
		A.setPixel(coord.at(0), getColour());
		coord.pop_back();
	}
};

class Line : public DrawObject{
public:
	Line(COORD a, COORD b, COLOUR c) : DrawObject(c) {
		//stores 1st and last coord
		coord.push_back(a);
		coord.push_back(b);
	}
	void draw(Drawing &A) {
		A.drawLine((coord.at(0)), coord.at(1), this->getColour());
		coord.pop_back();
	}

};


class Shape : public DrawObject {
private:

	//Initialize the variable in the same file, but after the class declaration
	static int shapeCount;

public:

	Shape(COLOUR c) : DrawObject(c) {
		shapeCount++;
	}

	void setCoord(COORD b) {
		coord.push_back(b);
	}

	void draw(Drawing &A) {
		for (int x = 0; x < coord.size() - 1; x++) {
			A.drawLine(coord.at(x), coord.at(x + 1), this->getColour());
		}
		A.drawLine(coord.back(), coord.front(), this->getColour());

		while (!coord.empty())
		{
			coord.pop_back();
		}
	}

	static int get_Num_Shapes() {
		return shapeCount;
	}

	~Shape() {
		shapeCount--;
	}

}; 

int Shape::shapeCount = 0;
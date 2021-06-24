//I tried my hardest but I could not get this program to run.
	/*
	assn3.exe test.bmp(file) 200(widthpix) 100(height) 127 127 127(rgbvals) S 255 0 0 4 10
	10 10 190 90 190 90 10 S 0 255 0 3 50 100 55 105 55 95 L 0 0 255 60 30 80 100 L 0 0 255
	80 100 60 170 P 0 0 0 25 70 P 0 0 0 25 130
	1. Create a Drawing object based on the program arguments.
	2. Create as many specific DrawObjects (Line,Point,Shape) as are requested by the program arguments,
	and store each of them in a single forward_list<DrawObject *>.
	3. Print out the number of Shapes that were created, using the static function you coded.
	4. Call the draw function for each DrawObject, remove it from the forward_list, and free the object
	memory.
	5. Save your image using the file name specified in the arguments, print out a message if it was
	successful or not.
	6. Print out the number of Shapes that remain, using the static function you coded.
	7. Prompt the user for a character before closing.
	*/
#include "Drawing.h"
#include <stdlib.h>
#include <forward_list>
#include "Drawable.h"
#include <iostream>
using namespace std;

COLOUR toColour(char *val[], int sz) {
	int r = atoi(val[sz + 1]), g = atoi(val[sz + 2]), b = atoi(val[sz + 3]);
	COLOUR clr = { static_cast<unsigned>(r), static_cast<unsigned>(g), static_cast<unsigned>(b) };
	return clr;
}
COORD toCoord(char *val[], int sz) {
	int row = atoi(val[sz + 1]), col = atoi(val[sz + 2]);
	COORD crd = { static_cast<unsigned>(row), static_cast<unsigned>(col) };
	return crd;
}

int main(int argc, char *argv[]) {
	
	//DRAW OBJECT--------------------------------------------------

	//forward list created
	forward_list<DrawObject*> List;

	COLOUR bck = toColour(argv, 4);
	Drawing img(static_cast<unsigned>(atoi(argv[3])), static_cast<unsigned>(atoi(argv[4])), bck);

	for (int pos = 8; pos <= argc; pos++) {

		if (*argv[pos] == 'P') {
			COORD pt = toCoord(argv, (pos + 3));
			COLOUR clr = toColour(argv, pos);
			//Point *P = new Point(pt, clr);
			Point *P = new Point(pt,clr);
			//created list item
			List.push_front(P);
		}
		else if (*argv[pos] == 'L') {
			COORD pt1 = toCoord(argv, (pos + 3));
			COORD pt2 = toCoord(argv, (pos + 5));
			COLOUR clr1 = toColour(argv, pos);
			Line *L = new Line(pt1, pt2, clr1);
			List.push_front(L);
		}
		else if (*argv[pos] == 'S') {
			COLOUR clr2 = toColour(argv, pos);
			Shape *S = new Shape(clr2);
			for (int i = 0; i < atoi(argv[pos + 4]); i++) {
				S->setCoord(toCoord(argv, i)); //(pos + 2 * i)
				}
			List.push_front(S);
			}
		}

	cout << "Number of Shapes: " << Shape::get_Num_Shapes() << endl;

	if (img.saveBMP(argv[2]) && List.empty())
	{
		cout << "test.bmp saved successfully" << endl;
	}

	else { cout << "test.bmp did not save" << endl; }

	img.saveBMP(argv[2]);

	cout << "ENTER: ";
	char c;
	cin >> c;
}

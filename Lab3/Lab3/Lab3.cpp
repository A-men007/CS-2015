#include <iostream>
#include "Box.h"

using namespace std;
//make Box object in a heap which doesn't destroy itself
Box *makeBox() {
	return new Box();
}
//step 25.
void destroyBox(Box *pntr) {

	delete(pntr);

}

//argc is the ARGument count or the # of args passed into the program
//argv[0] is the program name or file location when empty
int main(int argc, char *argv[]) {
	//step 16. create a object in a stack which does destroy itself after completing
	Box myBox;
	//17.
	Box *myBoxPtr = &myBox;
	//show file location
	cout << argv[0] << endl;
	for (int x = 1; x < argc; x++) {
		
		cout << argv[x] << endl;
		cout << (unsigned long)&argv[x] << endl;
		cout << (unsigned long)&argv[x] << endl;
		cout << (unsigned long)argv[x] << endl;

	}
	//step 13. print each character in the 2nd argument
	cout << sizeof(argv[1]) << endl;
		for (int s = 0; s < sizeof(argv[1])-1; s++) {
			cout << argv[1][s];
		}
		cout << endl;
		//18. set values (1,2,3)
		myBox.l = 1;
		myBox.w = 2;
		myBox.h = 3;

		cout << endl;
		//19.print from pntr
		cout << "Printing box attributes using pointer:" << endl;
		cout << myBoxPtr->l << endl;
		cout << myBoxPtr->w << endl;
		cout << myBoxPtr->h << endl;

		//step 22. create dynamic box object
		Box *dynBoxPtr;
		dynBoxPtr = new Box();
		delete dynBoxPtr;
		//26.
		Box * tempBoxPtr = makeBox();
		destroyBox(tempBoxPtr);

	cout << endl;
	system("PAUSE");
}
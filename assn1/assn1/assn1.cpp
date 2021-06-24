/* assn1.cpp (Calculator code): input of function code and arbitrarily long list of numbers
and print the function used, input and
result NOTE: INPUT IS GOING THROUGHH COMMAND PROMPT
Example inputs which have worked for me:
"C:\Users\amanp\OneDrive\Documents\Visual Studio 2017\Projects\assn1\Debug\assn1" F 1 2 4
"C:\Users\amanp\OneDrive\Documents\Visual Studio 2017\Projects\assn1\Debug\assn1" A 1 2 3
created by: Amanpreet Gill   date: Sept 27, 2018
*/
#include <iostream>
using namespace std;

void Sort(double *arr, int sz) {
	double temp;
	for (int x = 0; x < sz; x++) {
		if (arr[x + 1] < arr[x]) {
			temp = arr[x];
			arr[x] = arr[x + 1];
			arr[x + 1] = temp;
		}
	}
}
//Operation Functions 
double calcAverage(char * values[], int sz) {
	//ARRAY NOTATION (arr[])
	double Sum = 0;
	double *tarr;
	tarr = new double[sz];
	//perform copy
	for (int x = 0; x < 3; x++) {
		tarr[x] = atof(values[x]);
	}
	for (int x = 0; x < sz; x++) {
		Sum += tarr[x];
	}
	double Avg = Sum / sz;
	//freeing memory
	delete[] tarr;
	tarr = NULL;
	cout << "AVERAGE" << endl;
	return Avg;
}

double calcMedian(char * values[], int sz) {
	//POINTER NOTATION (*(values+i))
	//initalize variables/create secondary dynamic pointer
	int med = 0;
	double median = 0;

	double *tarr;
	tarr = new double[sz];
	//perform copy
	for (int x = 0; x < sz; x++) {
		*(tarr + x) = atof(*(values + x));
	}
	Sort(tarr, sz);
	if (sz % 2 == 0) {//even
		med = (sz / 2) - 1;
		//perform arithmatic
		median = ((*(tarr + med) + (*(tarr + (med + 1)))) / 2);
	}
	else {//odd
		med = ((sz + 1) / 2) - 1;
		median = *(tarr + med);
	}
	cout << "MEDIAN" << endl;
	//freeing memory
	return median;
	delete[] tarr;
	tarr = NULL;
}

double calcSum(char * values[]) {
	double sum = 0;
	//temp array for storing values
	double tarr[3];
	//perform copy
	for (int x = 0; x < 3; x++) {
		tarr[x] = atof(*(values + x));
	}
	for (int x = 0; x < 3; x++) {
		//add up sum
		sum += *(tarr + x);
	}
	//freeing memory
	cout << "SUM" << endl;
	return sum;
}

int main(int argc, char *argv[]) {
	//declare variables
	double out;
	//switch statement for the differ cases
	switch (*argv[1]) {
		//calc average
	case 'A':
		//func. called 
		//argc-2 b/c # of args in argv[2] stores values itself
		out = calcAverage(&argv[2], argc - 2);
		break;

		//calc median
	case 'M':
		//call func.
		out = calcMedian(&argv[2], argc - 2);
		break;

		//sum of all values
	case 'F':
		(argc - 2);
		out = calcSum(&argv[2]);
		break;
	}
	//display-------------------------------------------
	cout << "input values: ";
	for (int x = 2; x < ((argc - 2) + 2); x++) {
		cout << argv[x] << " ";
	}
	cout << "\noutput value: " << out << endl;
	system("PAUSE");
}
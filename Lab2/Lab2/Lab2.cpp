//

#include <iostream>
using namespace std;

//function to alphabetically add in capital letters to an array of said size
void init(char alpha[], int sz) {
	alpha[sz];

	for (int x = 0; x < sz; x++) {

		//fills in array with alphabetized values
		alpha[x] = 'A' + x % 26;
		//if the size exceeds Z, reset counter
		cout << alpha[x] << " ";

	}

}
//function to swap array values of index 1 with index 2
void swapElements(char arr[], int index1, int index2, int sz) {
	//temperary holder variable
	char temp;
	//perform swap
	temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
	 //print array
	cout << endl;
	//(sizeof(arr) / sizeof(arr[0]))
	for (int x = 0; x < sz; x++) {
		cout << arr[x] << " ";
	}
}
//function which will make use of your swap function.
void randomizeArray(char arr[], int sz) {
	char temp = NULL;

	cout << endl;
	for (int x = 0; x < sz; x++) {
		
		temp = arr[x];
		//randomize integer which range from 0-sz
		int r = rand() % sz;
		arr[x] = arr[r];
		arr[r] = temp; 
		//print
		cout << arr[x] << " ";
	}
}

//NEED TO FIX THIS FUNCTION
void bubbleSort(char arr[], int sz) {
	char temp = NULL;
	bool flag = true;
	cout << endl;
	//while true it stays in loop, otherwise it exits
	while (flag) {
		for (int x=0; x < sz; x++) {
			flag = false;
			//comparing int values 
			if ((arr[x]) > (arr[x+1])) {
				arr[x] = temp;
				arr[x] = arr[x + 1];
				arr[x + 1] = temp;
				flag = true;
				}
					
		}
		cout << "smd" << endl;
		flag = false;
	}
	cout << "bitch" << endl;
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {

	char Letter[3] = { 'A', 'B', 'C' };
	int swap1,swap2;
	char Alp[32];
	argc = 32;
	//Step 6
	cout << "Array=" << Letter[0]<<":"<< Letter[1] << ":" << Letter[2] << endl;
	
	//step 7
	argc = 32;
	init(Alp, argc);

	//step 8
	cout << "\nEnter 2 indexes you want to swap: ";
	cin >> swap1;
	cin >> swap2;
	swapElements(Alp, swap1, swap2, argc);

	//step 10
	randomizeArray(Alp, argc);

	//step 11
	bubbleSort(Alp, argc);

}
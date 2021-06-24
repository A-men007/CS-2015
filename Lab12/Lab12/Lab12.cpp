//#include <iostream>
//#include "LinkedList.h"
//using namespace std;
//
//int main(int argc, char *argv[]) {
//	
//	Stack<char> stack;
//	bool check = false;
//	int i = 0;
//	while (argv[1][i] != NULL) {
//		if (argv[1][i] == '{' || argv[1][i] == '(') {
//			stack.push(argv[1][i]);
//		} else {
//			char pop = stack.pop();
//			if ((pop == '{' && argv[1][i] == '}') || (pop == '(' && argv[1][i] == ')')) {
//				check = true;
//			}
//			else {
//				break;
//			}
//		}
//		i++;
//	}
//	if (check && stack.isEmpty()) {
//		cout << "Well formed parenthesis" << endl;
//	}
//	else {
//		cout << "Poorly formed parenthesis" << endl;
//	}
//	char c;
//	cin >> c;
//}
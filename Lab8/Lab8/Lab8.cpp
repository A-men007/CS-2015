#include <iostream>
using namespace std;

class Person {
private:
	int x;
public:
	virtual void print() { // the second output becomes "Student" from "Person" in a Person pointer which is intalized by student
		cout << "Person" << endl;
	}
	virtual void test() = 0;//abtracts the parent class and cannot be intantiated
	//since there isn't an overiding function in derived class, student can't be intantiated either
};

class Student : public Person {
public:
	void print() {
		cout << "Student" << endl;
	}
	virtual void test() {}
};

int main()
{
	//Person *pptr = new Person();
	Student *sptr = new Student();
	//pptr->print(); /* 1 */
	//prints "Person"
	//Pointer of person class calls print function 
	sptr->print(); /* 2 */
	//prints "Student"
	//Pointer of student class calls print function
	//pptr = sptr;
	//pptr->print(); /* 3 */
	//prints "Person"
	//Even though pptr is intalized by student, the pointer is still belings to Person 
	//code is not polymorphic yet...... need to add virtual to Person print
	//prints "Student"
	//((Student *)pptr)->print(); /* 4 */
	//print "Student"
	//pptr is casted to student class
	Person *pptr = sptr;
	pptr->print();
	//print "Person"

	char z;
	cin >> z;
}
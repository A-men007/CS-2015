#include <iostream>
#include <vector>
#include <string>
using namespace std;
//abtract class
class PCObject {
public:
	virtual void print() = 0;
	virtual ~PCObject();
};

class PrintableCollection {
public:
	vector<PCObject *>objs;
	void add(PCObject *po) {objs.push_back(po);}
	void printAll() { cout << "PrintableCollection" << endl;
	for (int x = 0; x < objs.size(); x++) { objs[x]->print(); }
	}
	~PrintableCollection() { for (int x = 0; x < objs.size(); x++) { delete objs[x]; } }
};
class Obj : public PCObject {
public:
	void print() { cout << "child.obj" << endl; }
	~Obj() {}
};
class MyString : public PCObject, public string {
public:
	MyString(string str) : string(str) {}
	void print() { cout << *this <<endl; }

};
int main(int argc, char *argv[]) {
	//PCObject pco;
	PrintableCollection coll;
	Obj * O = new Obj();
	coll.add(O);
	coll.printAll();
	MyString *ma = new MyString("");
	//ma->str = "Test";
	coll.add(ma);
	system("PAUSE");
}
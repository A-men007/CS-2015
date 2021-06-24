// copy, and move constructor should be created for programs that use dynamic memory
#include <iostream>
#include <string>
using namespace std;

class Country {
private: 
	//string class, string char is usually [J|A|Y|0]
	std::string name;
public:
	//declaration of country member name
	Country(string nm) : name(nm) {};
	//const allows name to be unchanged and return type needs to be addy for string type
	const string &getName() const { return name; }
};

class School {
private:
	string *pName;
public:
	//constructor for school class
	School(string nm) : pName(nullptr) { pName = new string(nm); };

	//cpy s1=s2 constructor makes sure the 2 strings don't share same memory location (and dont refer to the samething)
	School(const School &other) { pName = new string(*other.pName); }

	//move constructor s3 = s1+s2, this func. uses the temp obj of s1+s2 to cpy it into s3
	School(const School &&other) { pName = other.pName; *other.pName = nullptr; }

	//need destructor
	//deleting a nullptr will throw runtime errors***
	~School() { if (pName != nullptr) { delete pName; } }
	const string &getName() const { return *pName; }

	//s1=s2 but both obj are already declared and initalized so its differ than move constructor
	School operator=(const School &rhs) {
		//this if statement is for incase someone writes s1 = s1 then the lhs=rhs so we can't delete the memory we need
		//this != &rhs
		if (pName != rhs.pName) {
			delete pName;
		}
		pName = new string(*rhs.pName);
		//returns entire object which is ourselves
		return *this;
	}
};
class Person {
private: 
	string firstName, *plastName;
	Country *pCountry;
public:
	Person(string first, string last, Country *pCtry) :firstName(first), plastName(nullptr), pCountry(pCtry) {
		plastName = new string(last);
		
	}
	~Person() { delete plastName; }
	const string &getFirstNamer() { return firstName; }
	string getFullName() { return firstName + *plastName;}
	operator string() { return firstName; }
};

class Student : public Person{
private:
	School school;
public:
	Student(string first, string last, Country *pC, string sname) :
		Person(first, last, pC), school(sname) {

	}
	//overiding this from Person class
	//overiding must use same base class and parameters
	string getFullName() { return Person::getFullName()+"Student"; }
};

int main(int argc,char *argv[]) {
	//create school obj
	School s1("western");
	School s2("Laurier");
	//s3=s1=s2 same thing as s3(s1(s2))
	School s3(s2);
	
	Person p("Jay","fuckboi",nullptr);
	string nm;
	nm = string(p);
	cout << nm<<endl;
	Student s4("Jane", "Doe", nullptr, "Western");
	cout << s4.getFullName();
	char z;
	cin >> z;
	return 0;
}
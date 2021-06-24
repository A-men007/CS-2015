#pragma once
class Bag {
private:
	int object1;
	float object2;

public:
	Bag(int,double);
	inline void setObj1(int x) {
		object1 = x;
	}
	inline int getObj1() {
		return object1;
	}
	void setObj2(double);
	double getObj2();
	~Bag();
};


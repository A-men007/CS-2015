#pragma once

template <class item1, class item2>

class BagAnyDifferent {
private:
	item1 object1;
	item2 object2;

public:
	BagAnyDifferent(int c, double d) {
		setObj1(c);
		setObj2(d);
	}
	inline void setObj1(int x) {
		object1 = x;
	}
	inline int getObj1() {
		return object1;
	}
	void setObj2(double d) {
		object2 = d;
	}
	double getObj2() {
		return object2;
	}
	~BagAnyDifferent() {

	}
};


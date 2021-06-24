#pragma once

template <class Bag>

class BagAnySame {
private:
	Bag object1, object2;

public:
	BagAnySame(int c, double d) {
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
	~BagAnySame() {

	}
};

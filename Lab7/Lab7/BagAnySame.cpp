#include "BagAnySame.h"


Bag::Bag(int c, double d) {
	setObj1(c);
	setObj2(d);
}

void Bag::setObj2(double d) {
	object2 = d;
}
double Bag::getObj2() {
	return object2;
}

Bag::~Bag()
{
}

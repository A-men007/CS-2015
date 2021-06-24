#pragma once
#include "vector"
#include <iostream>
using namespace std;
template <class T, class O>
class OrderedList {
private:
	unsigned translate(unsigned request) const {
		return (request - 1);
	}
	vector <T> container;
public:
	unsigned getLength() const { return container.size(); }
	T retrieve(unsigned pos) const { return container.at(translate(pos)); }
	void insert(T item) {
		int k;
		for (k = 1; k <= getLength(); k++) {
			if (O::compare(item, retrieve(k)))
				break;
		}
		container.insert(container.begin() + translate(k), item);
	}
	template<class EQ> int find(T item) const {
		int i;
		for (i = 1; i <= getLength(); i++) {
			if (EQ::compare(item, retrieve(i)))
				return i;
		}
		return -1;
	}

	OrderedList(int DeSize = 5) { container.reserve(DeSize); }

};
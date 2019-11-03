#include <iostream>
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* v = nullptr;
		char type = in.get();
		if (type == 'c' || type == 'C') {
			in.ignore();//delete comma
			v = new Car(in);
		}
		return v;
	}
}
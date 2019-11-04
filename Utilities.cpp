#include <iostream>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* v = nullptr;
		std::string type;
		std::getline(in, type, ',');
		trim(type);
		if (type == "c" || type == "C") {
			v = new Car(in);
		}else if (type == "r" || type == "R") {
			v = new Racecar(in);
		}
		else {
			throw type[0];
		}
		in.ignore();//ignore either comma/ \n character
		return v;
	}

	void trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" \n\r\t"));
		str.erase(str.find_last_not_of(" \n\r\t") + 1);
	}
}
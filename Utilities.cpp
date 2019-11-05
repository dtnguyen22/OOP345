#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* v = nullptr;
		std::string type;
		if (std::getline(in, type, ',')) {
			std::string carstr;
			trim(type);
			if (type == "c" || type == "C") {
				std::getline(in, carstr, '\n');
				carstr += ","; //make it same format with racecar
				std::stringstream in(carstr);
				v = new Car(in);
			}
			else if (type == "r" || type == "R") {
				v = new Racecar(in);
			}
			else {
				std::getline(in, carstr); // clean in stream
				throw type[0];
			}
		}
		return v;
	}

	void trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" \n\r\t"));
		str.erase(str.find_last_not_of(" \n\r\t") + 1);
	}
}
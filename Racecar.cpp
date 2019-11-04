#include <iostream>
#include <string>
#include "Racecar.h"

namespace sdds {

	Racecar::Racecar(std::istream& in) : Car(in) {
		std::string str;
		std::getline(in, str, '\n');
		in >> this->m_booster;
		in.ignore();
	}

	void Racecar::display(std::ostream& os)const {
		Car::display(os);
		os << "*\n";
	}
	
	double Racecar::topSpeed() const {
		return this->m_booster;
	}


}
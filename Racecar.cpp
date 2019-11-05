#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Racecar.h"

namespace sdds {

	Racecar::Racecar(std::istream& in) :Car(in) {
		std::string boost;
		std::getline(in, boost, '\n');
		this->m_booster = stod(boost);
	}

	void Racecar::display(std::ostream& os)const {

		Car::display(os);
		os << std::setw(6) << std::fixed << std::setprecision(2) << this->topSpeed() << " |";
		os << "*";
	}

	double Racecar::topSpeed() const {
		return (this->m_booster + 1)*Car::topSpeed();
	}


}
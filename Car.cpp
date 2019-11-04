#include <iomanip>
#include <string>
#include "Utilities.h"
#include "Car.h"

namespace sdds {
	Car::Car() {
		this->m_condition = "";
		this->m_maker = "";
		this->m_speed = 0;
	}

	Car::Car(std::istream& is) {
		std::string carstr;
		std::getline(is, carstr, ','); //maker
		trim(carstr);
		this->m_maker = carstr;
		std::getline(is, carstr, ',');//condition
		trim(carstr);
		if (m_condition == "n" || m_condition == "") {
			this->m_condition = "new";
		}
		else if (m_condition == "u") {
			this->m_condition = "used";
		}
		else if (m_condition == "b") {
			this->m_condition = "broken";
		}
		else {
			throw "Invalid record";
		}
		is >> carstr; //speed
		try {
			this->m_speed = std::stod(carstr);
		}
		catch (...) {
			throw "Invalid record";
		}
	}

	std::string Car::condition() const {
		return this->m_condition;
	}

	double Car::topSpeed() const {
		return this->m_speed;
	}



	void Car::display(std::ostream& os) const {
		os << "| ";
		os << std::setw(10) << std::right << this->m_maker << " | ";
		os << std::setw(6) << std::left << this->m_condition << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << this->m_speed << " |";
	}


}
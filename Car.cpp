#include <iomanip>
#include <string>
#include <typeinfo> //typeid
#include "Utilities.h"
#include "Car.h"

namespace sdds {
	Car::Car() {
		this->m_condition = "";
		this->m_maker = "";
		this->m_speed = 0;
	}

	Car::Car(std::istream& ss) {
		std::string token;
		std::getline(ss, token, ','); //
		trim(token);
		this->m_maker = token;
		std::getline(ss, token, ',');//condition
		trim(token);
		if (token == "n" || token == "") {
			this->m_condition = "new";
		}
		else if (token == "u") {
			this->m_condition = "used";
		}
		else if (token == "b") {
			this->m_condition = "broken";
		}
		else {
			throw "Invalid record!";
		}
		std::getline(ss, token, ',');
		try {
			this->m_speed = std::stod(token);
		}
		catch (...) {
			std::getline(ss, token); //clean ss 
			throw "Invalid record!";
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
		if (typeid(*this) == typeid(Car)) {
			os << std::setw(6) << std::fixed << std::setprecision(2) << this->m_speed << " |";
		}
	}


}
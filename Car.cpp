#include <iomanip>
#include "Car.h"

namespace sdds {
	Car::Car() {
		this->m_condition = "";
		this->m_maker = "";
		this->m_speed = 0;
	}

	Car::Car(std::istream& is) {
		std::string carstr;
		std::string type;
		std::getline(is, carstr);
		this->m_maker = carstr.substr(0, carstr.find(','));
		carstr.erase(0, carstr.find(',') + 1);
		this->m_condition = carstr.substr(0, carstr.find(','));
		carstr.erase(0, carstr.find(',') + 1);
		trim(m_condition); trim(m_maker);
		this->m_speed = stod(carstr.substr(0, carstr.find('\n')));
		if (m_condition == "n") {
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
	}

	std::string Car::condition() const {
		return this->m_condition;
	}

	double Car::topSpeed() const {
		return this->m_speed;
	}

	void Car::trim(std::string& str) {
		str.erase(0, str.find_first_not_of(" \n\r\t"));
		str.erase(str.find_last_not_of(" \n\r\t") + 1);
	}

	void Car::display(std::ostream& os) const {
		os << "| ";
		os << std::setw(10) << std::right << this->m_maker << " | ";
		os << std::setw(6) << std::left << this->m_condition << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << this->m_speed << " |\n";
	}


}
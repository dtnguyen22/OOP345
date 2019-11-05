#include <iomanip>
#include <vector>
#include "Autoshop.h"
#include "Vehicle.h"

namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* vehicle) {
		this->m_vehicles.push_back(vehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& os) const {
		os << "--------------------------------\n";
		os << "| Cars in the autoshop!        |\n";
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			(*i)->display(os);
			os << '\n';
		}
		os << "--------------------------------\n";
	}


	Autoshop::~Autoshop() {
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			delete[] (*i);
		}
	}
}
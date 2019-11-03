#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"
namespace sdds {
	class Car: public Vehicle {
		std::string m_maker;
		std::string m_condition;
		double m_speed;
	public:
		Car();
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;
		void trim(std::string&);
	};
}


#endif
#ifndef _SDDS_RACECAR_H
#define _SDDS_RACECAR_H


#include <iostream>
#include "Car.h"
namespace sdds {
	class Racecar : public Car {
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream&) const;
		double topSpeed() const;
	};
}

#endif
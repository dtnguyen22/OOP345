#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		template <class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				// i.begin()/i contains the address of the vector, 
				// we need to dereference i to get the address of the element in the vector
				bool fastcar = test(*i);
				if (fastcar) {
					vehicles.push_back(*i);
				}
			}
		}

		//void operator()(const sdds::Vehicle*) {

		//}

		~Autoshop();
	};
}


#endif // !_SDDS_AUTOSHOP_H


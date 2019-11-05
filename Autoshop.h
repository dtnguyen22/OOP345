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
				//have to defererence to get the element,
				//in this case we will get the address of a vehicle
				bool fastcar = test(*i); //call lambda
				if (fastcar) {
					vehicles.push_back(*i); //add vehicles to list
				}
			}
		}
		~Autoshop();
	};
}


#endif // !_SDDS_AUTOSHOP_H


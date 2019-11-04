#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H

#include <iostream>
#include "Vehicle.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
	void trim(std::string&);
}

#endif
#include "Fleet.h"

void Fleet::addShipWithCloning(const Boat *ship) {
	Boat* toadd;
	ship->clone(toadd);
	this->fleet.push_back(toadd);
}

void Fleet::addShipWithFactory(const Boat* ship) {
	Boat* newShip = Boat::factory(ship->getType());
	this->fleet.push_back(newShip);
}

void Fleet::printFleet() const {
	std::cout << "Fleet members: \n";
	for (auto ship : fleet) {
		ship->print();
	}
}
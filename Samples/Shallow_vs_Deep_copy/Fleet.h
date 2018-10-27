#pragma once

#include "Boat.h"
#include <vector>
class Fleet
{
	std::vector<Boat *> fleet;

public:
	void addShipWithCloning(const Boat*);
	void addShipWithFactory(const Boat*);
	void printFleet() const;
};
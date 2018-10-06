#include "Boat.h"
#include "Submarine.h"
#include "Battleship.h"
Boat::Boat() :name("Empty boat") {}

Boat::Boat(const std::string& _name) :name(_name) {}

std::string Boat::getName() const {
	return this->name;
}

Boat* Boat::factory(std::string type) {
	if (type == "Submarine") {
		return new Submarine;
	}
	if (type == "Battleship") {
		return new Battleship;
	}
}
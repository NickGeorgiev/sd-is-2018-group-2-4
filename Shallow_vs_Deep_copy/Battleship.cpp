#include "Battleship.h"

Battleship::Battleship(std::string _name, int numGuns) : Boat(_name), numberOfGuns(numGuns) {}

std::string Battleship::getType() const {
	return "Battleship";
}

void Battleship::clone(Boat*& target) const {
	target = new Battleship(*this);
}

void Battleship::print() const {
	std::cout << "I am a battleship, called " << this->getName() << " and have " << this->numberOfGuns << " guns\n";
}
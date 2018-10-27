#include "Submarine.h"

Submarine::Submarine(const std::string _name, int _size) : Boat(_name), size(_size) {}

std::string Submarine::getType() const {
	return "Submarine";
}

void Submarine::clone(Boat*& target) const {
	target = new Submarine(*this);
}

void Submarine::print() const {
	std::cout << "I am the submarine " << this->getName() << " and with size " << this->size << '\n';
}

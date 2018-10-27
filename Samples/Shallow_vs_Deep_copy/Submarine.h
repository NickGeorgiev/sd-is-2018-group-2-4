#pragma once 

#include "Boat.h"

class Submarine : public Boat {
	int size;
public:
	Submarine() = default;
	Submarine(const std::string, int);
	std::string getType() const override;
	void clone(Boat*&) const override;
	void print() const override;
};
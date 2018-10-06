#pragma once
#include "Boat.h"

class Battleship : public Boat {
	int numberOfGuns;
public:
	Battleship() = default;
	Battleship(std::string, int);
	std::string getType() const override;
	void clone(Boat*&) const override;
	void print() const override;
};
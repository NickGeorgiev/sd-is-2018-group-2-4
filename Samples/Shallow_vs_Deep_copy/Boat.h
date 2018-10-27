#pragma once
#include <iostream>
#include <string>
class Boat{
	std::string name;
public:
	Boat();
	Boat(const std::string&);
	std::string getName() const;
	static Boat* factory(std::string);
	virtual std::string getType()const = 0;
	virtual void clone(Boat*&) const = 0;
	virtual void print() const = 0;
};


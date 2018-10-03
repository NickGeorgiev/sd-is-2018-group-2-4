#pragma once

#include <iostream>
#include <string>

class Boat
{
    std::string name;

  public:
    Boat(const std::string &_name) : name(_name) {}
    std::string getName() const {
        return this->name;
    }
    virtual void print() const = 0;
};
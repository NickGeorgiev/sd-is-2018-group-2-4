#pragma once

#include <iostream>
#include <string>
#include "Submarine.h"
#include "Battleship.h"
class Boat
{
    std::string name;

  public:
    static Boat *factory(std::string name)
    {
        switch (name)
        {
            case "Sub":
                {
                    return new Submarine("asdf", 123);
                    break;
                }
            case "Bat":
                {
                    return new Battleship("asdf", 123);
                    break;
                }
        }
    }
    virtual char* getType() {}=0;
    Boat(const std::string &_name) : name(_name) {}
    std::string getName() const
    {
        return this->name;
    }
    virtual void clone(Boat*&)=0;
    virtual void print() const = 0;
};
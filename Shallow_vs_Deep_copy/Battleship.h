#pragma once

#include "Boat.h"

class Battleship: public Boat {
    int numberOfGuns;
    public:
    Battleship(std::string _name, int numGuns): Boat(_name), numberOfGuns(numGuns){}
    void print() const {
        std::cout<<"I am a battleship, called "<<this->getName()<<" and have "<< this->numberOfGuns << " guns\n";
    }
};
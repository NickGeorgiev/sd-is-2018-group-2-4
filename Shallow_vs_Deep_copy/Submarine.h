#pragma once 

#include "Boat.h"

class Submarine: public Boat {
    int size;
    public:
    Submarine(const std::string _name, int _size): Boat(_name), size(_size){}
    char* getType() {
        return "Sub";
    }
    void clone(Boat*& target) {
        target=new Submarine(*this);
    }
    void print() const {
        std::cout<<"I am the submarine "<<this->getName()<<" and with size "<<this->size<<'\n';
    }
};
#pragma once

#include "Boat.h"
#include <vector>
class Fleet
{
    std::vector<Boat *> fleet;

  public:
    void addShip(const Boat *ship)
    {
       Boat* newShip = Boat::factory(ship->getType());
       //...трябва да приравним корабите
       fleet.push(newShip);

       Boat* toAdd;
       ship->clone(toAdd);

    }
    void printFleet() const
    {
        // for (int i = 0; i < fleet.size(); i++)
        // {
        //     fleet[i]->print();
        // }
        for (auto ship : fleet)
        {
            ship->print();
        }
    }
};
#include "Boat.h"
#include "Submarine.h"
#include "Battleship.h"

int main() {
    Submarine sub("Black widow", 133);
    sub.print();
    Battleship bat("Red panther",17);
    bat.print();
}
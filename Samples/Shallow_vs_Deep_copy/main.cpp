#include "Boat.h"
#include "Submarine.h"
#include "Battleship.h"
#include "Fleet.h"
int main() {
    Submarine sampleSubmarine("Black widow", 133);
	sampleSubmarine.print();
    Battleship sampleBattleship("Red panther", 17);
	sampleBattleship.print();
	Battleship sampleCopyOfBattleship(sampleBattleship);
	sampleBattleship.print();
	Fleet sampleFleet;
	sampleFleet.addShipWithCloning(&sampleSubmarine);
	sampleFleet.addShipWithCloning(&sampleBattleship);
	sampleFleet.printFleet();
	return 0;
}
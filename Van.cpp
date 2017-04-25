//
// Created by shan on 10/28/16.
//

#include "includes/Van.hpp"

int Van::objectCount = 0;

double Van::getCargoVolume() const {
    return cargoVolume;
}

void Van::setCargoVolume(double cargoVolume) {
    Van::cargoVolume = cargoVolume;
}

Van::Van(string idPlate, string brand, DateTime entryTime, double cargoVolume)
        : cargoVolume(cargoVolume) {
    this->idPlate = idPlate;
    this->brand = brand;

    parkingLotOccupancy = 2;
    objectCount++;
}

string Van::toString() const {
    return idPlate + "\t\t" + entryTime.toString() + "\t\tVan";
}

Van::~Van() {
    objectCount--;
}

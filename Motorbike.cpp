//
// Created by shan on 10/28/16.
//

#include "includes/Motorbike.hpp"

int Motorbike::objectCount = 0;

double Motorbike::getEngineSize() const {
    return engineSize;
}

void Motorbike::setEngineSize(double engineSize) {
    Motorbike::engineSize = engineSize;
}

Motorbike::Motorbike(string idPlate, string brand, DateTime entryTime, double engineSize)
        : engineSize(engineSize) {
    this->idPlate = idPlate;
    this->brand = brand;
    this->entryTime = entryTime;
    objectCount++;
}

string Motorbike::toString() const {
    return idPlate + "\t\t" + entryTime.toString() + "\t\tMotorbike";
}

Motorbike::~Motorbike() {
    objectCount--;
}

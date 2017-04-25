//
// Created by shan on 10/28/16.
//

#include "includes/Car.hpp"

int Car::objectCount = 0;

int Car::getNoOfDoors() const {
    return noOfDoors;
}

void Car::setNoOfDoors(int noOfDoors) {
    Car::noOfDoors = noOfDoors;
}

const string &Car::getColor() const {
    return color;
}

void Car::setColor(const string &color) {
    Car::color = color;
}

string Car::toString() const {
    return idPlate + "\t\t" + entryTime.toString() + "\t\tCar";
}

Car::Car(string idPlate, string brand, DateTime entryTime, int noOfDoors, string color)
        : noOfDoors(noOfDoors), color(color) {
    this->idPlate = idPlate;
    this->brand = brand;
    objectCount++;
}

Car::~Car() {
    objectCount--;
}

//
// Created by shan on 10/28/16.
//

#include "includes/Vehicle.hpp"


const string &Vehicle::getIdPlate() const {
    return idPlate;
}

void Vehicle::setIdPlate(const string &idPlate) {
    Vehicle::idPlate = idPlate;
}

const string &Vehicle::getBrand() const {
    return brand;
}

void Vehicle::setBrand(const string &brand) {
    Vehicle::brand = brand;
}

const DateTime & Vehicle::getEntryTime() const {
    return entryTime;
}

void Vehicle::setEntryTime(DateTime entryTime) {
    Vehicle::entryTime = entryTime;
}




//
// Created by shan on 11/3/16.
//

#ifndef OOP_CW1_CARPARKMANAGER_HPP
#define OOP_CW1_CARPARKMANAGER_HPP


#include "Vehicle.hpp"

/*
 * @author - Gayashan Bombuwala
 * TODO - facilitate factory method design pattern
 */
class CarParkManager {

public:
    virtual int addVehicle() = 0;

    virtual void deleteVehicle() = 0;

    virtual void displayVehicleList() = 0;

    virtual void displayVehicleList(string date) = 0;

    virtual void displayStats() = 0;

    virtual void displayParkingCosts() = 0;

    virtual void runMenu() = 0;
};


#endif //OOP_CW1_CARPARKMANAGER_HPP

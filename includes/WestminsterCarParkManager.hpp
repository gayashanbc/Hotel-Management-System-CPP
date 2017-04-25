//
// Created by shan on 11/3/16.
//

#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "CarParkManager.hpp"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::vector;


class WestminsterCarParkManager : public CarParkManager {

    vector<Vehicle *> vehicleList;// to be used with class operations
    vector<Vehicle *> vehicleLog;// to be used with save operations

public:
    static int parkingLotCount;

    int addVehicle() override;

    void deleteVehicle() override;

    void displayVehicleList() override;

    void displayVehicleList(string date) override;

    void displayStats() override;

    void displayParkingCosts() override;

    void runMenu() override;

    void saveData();
};




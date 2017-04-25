//
// Created by shan on 10/28/16.
//

#pragma once

#include <iostream>

#include "DateTime.hpp"

using std::string;

/*
 * @author - Gayashan Bombuwala
 * TODO - facilitate polymorphism
 */
class Vehicle {

protected:

    string idPlate;
    string brand;
    DateTime entryTime;
public:

    int parkingLotOccupancy = 1;

    const DateTime & getEntryTime() const;

    void setEntryTime(DateTime entryTime);

    const string &getIdPlate() const;

    void setIdPlate(const string &idPlate);

    const string &getBrand() const;

    void setBrand(const string &brand);

    virtual string toString() const= 0;

};




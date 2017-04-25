//
// Created by shan on 10/28/16.
//

#ifndef OOP_CW1_CAR_HPP
#define OOP_CW1_CAR_HPP

#include <iostream>

#include "Vehicle.hpp"



using std::string;

class Car : public Vehicle {
    int noOfDoors;
    string color;
public:
    static int objectCount;

    int getNoOfDoors() const;

    void setNoOfDoors(int noOfDoors);

    const string &getColor() const;

    virtual ~Car();

    void setColor(const string &color);

    Car(string, string, DateTime, int, string);

    string toString() const override ;

};


#endif //OOP_CW1_CAR_HPP

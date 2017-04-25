//
// Created by shan on 10/28/16.
//

#ifndef OOP_CW1_VAN_HPP
#define OOP_CW1_VAN_HPP


#include "Vehicle.hpp"

class Van : public Vehicle {
    double cargoVolume;
public:
    static int objectCount;

    double getCargoVolume() const;

    void setCargoVolume(double cargoVolume);

    Van(string, string, DateTime, double);

    string toString() const override ;

    ~Van();


};


#endif //OOP_CW1_VAN_HPP

//
// Created by shan on 10/28/16.
//

#ifndef OOP_CW1_MOTORBIKE_HPP
#define OOP_CW1_MOTORBIKE_HPP


#include "Vehicle.hpp"

class Motorbike : public Vehicle {

double engineSize;

public:
    static int objectCount;

    Motorbike(string, string, DateTime, double);

    double getEngineSize() const;

    void setEngineSize(double engineSize);

    string toString() const override ;

    ~Motorbike();
};


#endif //OOP_CW1_MOTORBIKE_HPP

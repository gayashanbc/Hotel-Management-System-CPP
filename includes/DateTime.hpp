//
// Created by shan on 10/28/16.
//

#pragma once

#include <iostream>
#include <ctime>

using std::string;

/*
 * @author - Gayashan Bombuwala
 * TODO - to store and perform operations on the entry time of vehicles
 */
class DateTime {

public:
    enum months {
        JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
    };

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    int getHour() const;

    void setHour(int hours);

    int getMin() const;

    void setMin(int min);

    string toString() const;

    DateTime(int, int, int);

    DateTime();

    int operator-(const DateTime &) const;

    static bool validateDate(int year, int month, int day);

    static int getDays(int year, int month);

    string toDate() const;

private:
    int year,

            day,
            hour,
            min;

    months month;
};



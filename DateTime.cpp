//
// Created by shan on 10/28/16.
//

#include "includes/DateTime.hpp"

using std::to_string;
using std::cout;
using std::endl;

/*
 * TODO - convert class fields to YYYY-MM-DD HH24:MIN date format
 * @return - formatted date/time String
 */
string DateTime::toString() const {
    return (to_string(year)) + "/" + (to_string(month)) + "/" + (to_string(day))
           + " at " + (to_string(hour)) + ":" + (to_string(min));
}

int DateTime::getYear() const {
    return year;
}

void DateTime::setYear(int year) {
    DateTime::year = year;
}

int DateTime::getMonth() const {
    return months(month);
}

void DateTime::setMonth(int month) {
    DateTime::month = (months) month;
}

int DateTime::getDay() const {
    return day;
}

void DateTime::setDay(int day) {
    DateTime::day = day;
}

int DateTime::getHour() const {
    return hour;
}


void DateTime::setHour(int hours) {
    DateTime::hour = hours;
}

int DateTime::getMin() const {
    return min;
}

void DateTime::setMin(int min) {
    DateTime::min = min;
}

/*
 * default constructor TODO - assign values to class fields using system
 * date and time
 */
DateTime::DateTime() {
    time_t timeInSeconds = time(0);
    tm *currentDateTime = localtime(&timeInSeconds);
    year = currentDateTime->tm_year + 1900,
    month = (months) (currentDateTime->tm_mon + 1),
    day = currentDateTime->tm_mday,
    hour = currentDateTime->tm_hour,
    min = currentDateTime->tm_min;
}

/*
 * TODO - calculate the hour difference between the two DateTime objects
 * @param dateTime - the DateTime object that needs to be calculated the
 * hour difference with
 * @return - hours difference between the two DateTime objects
 */
int DateTime::operator-(const DateTime &rhs) const {
    int minDif = 0, hourDif = 0, dayDif = 0;
    dayDif = rhs.getDay() - this->getDay();
    hourDif = rhs.getHour() - this->getHour();
    minDif = rhs.getMin() - this->getMin();

    hourDif += dayDif > 0 ? dayDif * 24 : 0;
    hourDif += minDif >= 30 ? 1 : 0;
    hourDif = hourDif == 0 ? 1 : hourDif;//to make sure at least 1 hour is calculated

    return hourDif;
}

DateTime::DateTime(int year, int month, int day)
        : year(year), month((months) month), day(day) {
}

/*
 * TODO - validate a date
 * @param year - year of the date
 * @param month - month of the date
 * @param day - day of the date
 * @return - isValid
 */
bool DateTime::validateDate(int year, int month, int day) {
    if (to_string(year).length() != 4) {
        cout << "\n\tInvalid date!" << endl;
        return false;
    } else if (to_string(month).length() != 1 && to_string(month).length() != 2) {
        cout << "\n\tInvalid date!" << endl;
        return false;
    } else if (to_string(day).length() != 1 && to_string(day).length() != 2) {
        cout << "\n\tInvalid date!" << endl;
        return false;
    } else if (month < 1 || month > 12) {
        cout << "\n\tInvalid date!" << endl;
        return false;
    } else if ((day < 1 || day > getDays(year, month))) {
        cout << "\n\tInvalid date!" << endl;
        return false;
    } else {
        return true;
    }
}

/*
 * TODO - find the number of days for a particular month of a given year
 * @param year - year of the date
 * @param month - month of the date
 * @return - the number of days in the particular month
 */
int DateTime::getDays(int year, int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2 && year % 400 == 0) { // leap year check
        return 29;
    } else {
        return 28;
    }
}

/*
 * TODO - convert class fields to YYYY-MM-DD date format
 * @return - formatted date String
 */
string DateTime::toDate() const {
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
}





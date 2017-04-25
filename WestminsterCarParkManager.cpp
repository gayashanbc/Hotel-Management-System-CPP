//
// Created by shan on 11/3/16.
//

#include "includes/WestminsterCarParkManager.hpp"
#include "includes/Car.hpp"
#include "includes/Van.hpp"
#include "includes/Motorbike.hpp"

int WestminsterCarParkManager::parkingLotCount = 20;

/*
 * TODO - add a vehicle to the car park
 */
int WestminsterCarParkManager::addVehicle() {
    char choice;
    bool isGoBackTrue = false, isAddingSuccessful = false;
    string idPlate, brand, color;
    double engineSize, cargoVolume;
    int noOfDoors;
    DateTime *dateTime;
    Vehicle *vehicle;

// run the menu until user chooses to go back
    while (!isGoBackTrue) {
        cout << "\n\t(1) Add a car" << endl;
        cout << "\t(2) Add a van" << endl;
        cout << "\t(3) Add a motorbike" << endl;
        cout << "\t(4) Go back" << endl;
        cout << "\n\tEnter a choice1 >> ";

        cin >> choice;

        // check for valid vehicle choices
        if (choice == '1' || choice == '2' || choice == '3') {
            cout << "\n\tEnter the ID Plate number >> ";
            cin >> idPlate;
            cout << "\tEnter the brand >> ";
            cin >> brand;
            dateTime = new DateTime;
        }

        // present secondary questions based on the vehicle type
        switch (choice) {
            case '1' : {

                cout << "\tEnter the number of doors >> ";
                cin >> noOfDoors;
                cout << "\tEnter the color >> ";
                cin >> color;

                vehicle = new Car(idPlate, brand, *dateTime, noOfDoors, color);

                isAddingSuccessful = true;

                break;
            }
            case '2' : {
                cout << "\tEnter the cargo volume (in kilograms) >> ";
                cin >> cargoVolume;

                vehicle = new Van(idPlate, brand, *dateTime, cargoVolume);

                isAddingSuccessful = true;
                break;
            }
            case '3' : {
                cout << "\tEnter the engine size (in CC) >> ";
                cin >> engineSize;

                vehicle = new Motorbike(idPlate, brand, *dateTime, engineSize);

                isAddingSuccessful = true;
                break;
            }

            case '4':
                isGoBackTrue = true;
                break;

            default:
                cout << "\n\tInvalid choice1! Try again..." << endl;
                break;
        }

        // continue if inputs were taken successfully
        if (isAddingSuccessful) {
            if (parkingLotCount >= vehicle->parkingLotOccupancy) {
                vehicleList.push_back(vehicle);
                vehicleLog.push_back(vehicle);
                parkingLotCount -= vehicle->parkingLotOccupancy; // reduce parking lot amount
                cout << "\n\tThe Vehicle (" + idPlate + ") has been successfully added to the parking lot" << endl;
                cout << "\tAvailable parking lot count : " << parkingLotCount << endl;
            } else {
                cout << "\n\tNo enough parking lots available at the moment" << endl;
            }
            isAddingSuccessful = false;
        }
    }

    isGoBackTrue = false;
    vehicle = nullptr;
    delete dateTime;
    return parkingLotCount;
}

/*
 * TODO - remove a vehicle from the car park
 */
void WestminsterCarParkManager::deleteVehicle() {
    string idPlate;
    Vehicle *vehicle = nullptr;
    int pos = -1;

    cout << "\n\tEnter the ID Plate number >> ";
    cin >> idPlate;

    // loop to find a matching record
    for (unsigned int i = 0; i < vehicleList.size(); i++) {
        if (vehicleList[i]->getIdPlate() == idPlate) {
            pos = i;
            vehicle = vehicleList[pos];
            break;
        }
    }

    // print the result
    if (pos == -1) { // no record is found
        cout << "\n\tNo vehicle found with the ID Plate: " + idPlate << endl;
    } else {
        cout << "\n\tVehicle (" + idPlate + ") has been removed from the parking lot!" << endl;

        parkingLotCount += vehicle->parkingLotOccupancy;
        pos = -1;
        vehicle = nullptr;
        vehicleList.erase(vehicleList.begin() + pos);
    }
}

/*
 * TODO - display currently parked vehicle list
 */
void WestminsterCarParkManager::displayVehicleList() {
    if (vehicleList.size() > 0) { // no vehicles were parked
        cout << "\n\tID Plate\tEntry Time\t\t\t\tType\n" << endl;
        for (unsigned long i = vehicleList.size(); i-- > 0;) {
            cout << "\t" << vehicleList[i]->toString() << endl;
        }
    } else {
        cout << "\n\tNo vehicles have been currently parked!" << endl;
    }

}

/*
 * TODO - display some statistics about the car park
 */
void WestminsterCarParkManager::displayStats() {
    if (vehicleList.size() > 0) {
        int dif = 0, max = 0, pos;
        DateTime dateTime;

        double total = Car::objectCount + Van::objectCount + Motorbike::objectCount;
        cout << "\n\tCars in the park: " << ((double) Car::objectCount / total) * 100 << "%" << endl;
        cout << "\tVans in the park: " << ((double) Van::objectCount / total) * 100 << "%" << endl;
        cout << "\tMotorbikes in the park: " << ((double) Motorbike::objectCount / total) * 100 << "%" << endl;

        // find the longest parked vehicle
        for (unsigned int i = 0; i < vehicleList.size(); i++) {
            Vehicle *vehicle = vehicleList[i];
            dif = vehicle->getEntryTime() - dateTime;
            if (dif > max) {
                max = dif;
                pos = i;
            }
        }

        cout << "\n\tLongest parked vehicle:\t" << vehicleList[pos]->toString() << endl;
        cout << "\tLast parked vehicle:\t" << vehicleList[vehicleList.size() - 1]->toString() << endl;
        total = 0, dif = 0, max = 0, pos = 0;
    } else {
        cout << "\n\tNo vehicles have been currently parked!" << endl;
    }
}

/*
 * TODO - display the parking costs of currently parked vehicles
 */
void WestminsterCarParkManager::displayParkingCosts() {
    if (vehicleList.size() > 0) { // if no vehicles were parked
        DateTime currentTime;
        int dif;
        double parkingCost;

        cout << "\n\tID Plate\tParking Cost\n" << endl;


        // calculate parking cost for each vehicle
        for (Vehicle *vehicle : vehicleList) {
            parkingCost = 0;
            dif = vehicle->getEntryTime() - currentTime; // get parked time period

            // cost basis depending on the no. of hours
            if (dif > 3) {
                parkingCost += (3 * 3);
                dif -= 3;
                for (int i = 0; i < dif; i++) {
                    parkingCost += 1;
                }
            } else {// if less than 3 hours
                for (int i = 0; i < dif; i++) {
                    parkingCost += 3;
                }
            }
            cout << "\t" + vehicle->getIdPlate() + "\t\t" << parkingCost << " GBP" << endl;


        }
    } else {
        cout << "\n\tNo vehicles have been currently parked!" << endl;
    }
}

/*
 * TODO - display the menu of the car park
 */
void WestminsterCarParkManager::runMenu() {
    DateTime dateTime;
    cout << "\n\t\t\tWelcome to Westminster Car Park Management System" << endl;
    cout << "\t\t\t\t\t" << dateTime.toString() << "\n" << endl;
    char choice;
    bool shouldExit = false;


    while (!shouldExit) {
        cout << "\n\t(1) Add a vehicle" << endl;
        cout << "\t(2) Delete a vehicle" << endl;
        cout << "\t(3) Display current vehicle list" << endl;
        cout << "\t(4) Display statistics" << endl;
        cout << "\t(5) Display parking costs" << endl;
        cout << "\t(6) Display vehicles parked on a specific date" << endl;
        cout << "\t(7) Exit" << endl;
        cout << "\n\tEnter a choice >> ";

        cin >> choice;


        switch (choice) {
            case '1':
                addVehicle();
                break;

            case '2':
                deleteVehicle();
                break;

            case '4':
                displayStats();
                break;

            case '5':
                displayParkingCosts();
                break;

            case '7':
                if (vehicleLog.size() > 0) {
                    saveData();
                }
                shouldExit = true;
                break;
            case '3':
                displayVehicleList();
                break;
            case '6': {
                int year, month, day;

                // by pass invalid inputs and get the date
                do {
                    cout << "\n\tEnter the entry date (YYYY MM DD) >> ";
                    cin >> year >> month >> day;
                } while (!DateTime::validateDate(year, month, day));
                DateTime dt(year, month, day);
                displayVehicleList(dt.toDate());
                break;
            }
            default:
                cout << "\n\tInvalid choice1! Try again..." << endl;
                break;
        }
    }
}

/*
 * TODO - display vehicle parked on a specified date
 * @param date - date that needs to be searched for parked vehicles
 */
void WestminsterCarParkManager::displayVehicleList(string date) {
    string parkDate, idPlate;
    std::ifstream file;
    file.open("saveData.txt");
    cout << endl;
    int count = 0;

    while (true) {
        file >> parkDate;
        file >> idPlate;
        if (file.eof()) {
            break;
        } else {
            if (parkDate == date) {
                cout << "\t" << parkDate << "\t" << idPlate << endl;
                count++;
            }
        }
    }

    if (count == 0) {
        cout << "\n\tNo records were found on: " << date << endl;
    }
    file.close();
}

void WestminsterCarParkManager::saveData() {
    std::ofstream file;
    file.open("saveData.txt", std::ios::app);
    for (Vehicle *vehicle:vehicleLog) {
        file << vehicle->getEntryTime().toDate() << " " << vehicle->getIdPlate() << endl;
    }
    file.close();
}




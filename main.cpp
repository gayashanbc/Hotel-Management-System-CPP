#include <iostream>

#include "includes/WestminsterCarParkManager.hpp"


using namespace std;

int main() {


    try {
        CarParkManager *carParkManager = new WestminsterCarParkManager;
        carParkManager->runMenu();
        delete carParkManager;


    }catch (...){
        std::cerr << "\n\tProblem encountered! Restarting...." << endl;
        main();
    }
    return 0;
}
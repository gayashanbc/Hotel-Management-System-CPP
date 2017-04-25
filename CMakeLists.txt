cmake_minimum_required(VERSION 3.6)
project(OOP_CW1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vehicle.cpp includes/Vehicle.hpp DateTime.cpp includes/DateTime.hpp Car.cpp includes/Car.hpp Van.cpp includes/Van.hpp Motorbike.cpp includes/Motorbike.hpp CarParkManager.cpp includes/CarParkManager.hpp WestminsterCarParkManager.cpp includes/WestminsterCarParkManager.hpp DB_Connection.cpp includes/DB_Connection.hpp)
add_executable(OOP_CW1 ${SOURCE_FILES})
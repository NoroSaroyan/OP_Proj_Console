cmake_minimum_required(VERSION 3.27)
project(OP_Proj_Console)

set(CMAKE_CXX_STANDARD 17)

add_executable(OP_Proj_Console main.cpp
        Entities/car/Car.h
        Entities/car/BodyType.h
        Entities/car/Transmission.h
        Entities/car/Car.cpp
        Entities/order/Order.h
        Entities/order/Order.cpp
        Services/CarService.h
        Services/CarService.h
        Services/CarService.cpp)

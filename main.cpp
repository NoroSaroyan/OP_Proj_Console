#include <iostream>
#include <vector>
#include <string>
#include "Entities/car/Car.h"
#include "Entities/order/Order.h"
#include "Services/order/OrderService.h"
#include "Services/car/CarService.h"

std::vector<Car> cars;
std::vector<Order> orders;

int displayMenu(const std::vector<std::string>& options) {
    std::cout << "Welcome to the Car Rental Service!\n";
    std::cout << "Please select an option:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << i + 1 << ". " << options[i] << '\n';
    }
    std::cout << "Enter your choice (1-" << options.size() << "): ";

    int choice;
    std::cin >> choice;
    return choice;
}

int main() {
//    std::vector<std::string> menuOptions = {"Catalog", "Order a car"};
//
//    int choice;
//    do {
//        choice = displayMenu(menuOptions);
//
//        switch (choice) {
//            case 1:
//                std::cout << "Displaying catalog...\n";
//                break;
//            case 2:
//                std::cout << "Ordering a car...\n";
//                break;
//            default:
//                std::cout << "Invalid choice. Please try again.\n";
//                break;
//        }
//    } while (choice < 1 || choice > menuOptions.size());


    cars.push_back(Car("1", "Toyota", "Camry", "2.5L", SEDAN, AUTOMATIC, true));
    cars.push_back(Car("2", "Honda", "Civic", "2.0L", SEDAN, MANUAL, false));
    cars.push_back(Car("3", "Ford", "F-150", "5.0L", TRUCK, AUTOMATIC, true));

    CarService carService;

    std::cout << "List of all cars:\n";
    carService.displayAllCars();
    std::cout<<std::endl;
    std::cout<<std::endl;

    OrderService orderService;

    orderService.addOrder(Order("101", std::chrono::system_clock::now(), std::chrono::system_clock::now(), "1", "1001", 200.0));
    orderService.addOrder(Order("102", std::chrono::system_clock::now(), std::chrono::system_clock::now(), "2", "1002", 250.0));
    orderService.addOrder(Order("103", std::chrono::system_clock::now(), std::chrono::system_clock::now(), "3", "1003", 300.0));

    std::cout << "\nList of all orders:\n";
    orderService.displayAllOrders();
    std::cout<<std::endl;
    std::cout<<std::endl;

    Order newOrder("101", std::chrono::system_clock::now(), std::chrono::system_clock::now(), "1", "1001", 220.0);
    orderService.editOrder("101", newOrder);

    std::cout << "\nList of all orders after editing:\n";
    orderService.displayAllOrders();
    std::cout<<std::endl;
    std::cout<<std::endl;

    orderService.deleteOrder("102");

    std::cout << "\nList of all orders after deletion:\n";
    orderService.displayAllOrders();
    std::cout<<std::endl;
    std::cout<<std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include "Entities/car/Car.h"
#include "Entities/order/Order.h"
#include "Services/order/OrderService.h"
#include "Services/car/CarService.h"
using namespace std;

vector<Car> cars;
vector<Order> orders;

int displayMenu(const vector<string>& options) {
    cout << "Welcome to the Car Rental Service!\n";
    cout << "Please select an option:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        cout << i + 1 << ". " << options[i] << '\n';
    }
    cout << "Enter your choice (1-" << options.size() << "): ";

    int choice;
    cin >> choice;
    return choice;
}

//    vector<string> menuOptions = {"Catalog", "Order a car"};
//
//    int choice;
//    do {
//        choice = displayMenu(menuOptions);
//
//        switch (choice) {
//            case 1:
//                cout << "Displaying catalog...\n";
//                break;
//            case 2:
//                cout << "Ordering a car...\n";
//                break;
//            default:
//                cout << "Invalid choice. Please try again.\n";
//                break;
//        }
//    } while (choice < 1 || choice > menuOptions.size());


int main() {
    cars.push_back(Car("1", "Toyota", "Camry", "2.5L", SEDAN, AUTOMATIC, true));
    cars.push_back(Car("2", "Honda", "Civic", "2.0L", SEDAN, MANUAL, false));
    cars.push_back(Car("3", "Ford", "F-150", "5.0L", TRUCK, AUTOMATIC, true));

    CarService carService;
    OrderService orderService;
    orderService.addOrder(Order("101", chrono::system_clock::now(), chrono::system_clock::now(), "1", "1001", 200.0));
    orderService.addOrder(Order("104", chrono::system_clock::now(), chrono::system_clock::now(), "1", "1004", 200.0));
    orderService.addOrder(Order("102", chrono::system_clock::now(), chrono::system_clock::now(), "2", "1002", 250.0));
    orderService.addOrder(Order("103", chrono::system_clock::now(), chrono::system_clock::now(), "3", "1003", 300.0));

    orderService.displayAllOrders();
    cout << endl;

    string orderIdToFind = "102";
    cout << "Finding order by ID '" << orderIdToFind << "':\n";
    Order* foundOrderByOrderId = orderService.findOrderByOrderId(orderIdToFind);
    if (foundOrderByOrderId != nullptr) {
        cout << "Order ID: " << foundOrderByOrderId->getId() << ", User ID: " << foundOrderByOrderId->getClientId() << ", Price: " << foundOrderByOrderId->getPrice() << "\n";
    } else {
        cout << "Order not found.\n";
    }
    cout << endl;

    string userIdToFind = "1";
    cout << "Finding orders by user ID '" << userIdToFind << "':\n";
    vector<Order> foundOrdersByUserId = orderService.findOrdersByUserId(userIdToFind);
    for (const auto& order : foundOrdersByUserId) {
        cout << "Order ID: " << order.getId() << ", User ID: " << order.getClientId() << ", Price: " << order.getPrice() << "\n";
    }
    cout << endl;

    string carIdToFind = "1";
    cout << "Finding orders by car ID '" << carIdToFind << "':\n";
    vector<Order> foundOrdersByCarId = orderService.findOrdersByCarId(carIdToFind);
    for (const auto& order : foundOrdersByCarId) {
        cout << "Order ID: " << order.getId() << ", Car ID: " << order.getCarId() << ", Price: " << order.getPrice() << "\n";
    }
    cout << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <string>

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
    std::vector<std::string> menuOptions = {"Catalog", "Order a car"};

    int choice;
    do {
        choice = displayMenu(menuOptions);

        switch (choice) {
            case 1:
                std::cout << "Displaying catalog...\n";
                break;
            case 2:
                std::cout << "Ordering a car...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice < 1 || choice > menuOptions.size());

    return 0;
}

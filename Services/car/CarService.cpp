#include "CarService.h"

#include <algorithm>

namespace CarMapper {
    std::string serialize(const Car& car) {
        std::ostringstream oss;
        oss << car.getId() << ',' << car.getBrand() << ',' << car.getModel() << ',' << car.getVolume() << ','
            << static_cast<int>(car.getBodyType()) << ',' << static_cast<int>(car.getTransmission()) << ','
            << car.getRate() << ',' << car.isHasCarSeat();
        return oss.str();
    }

    Car deserialize(const std::string& str) {
        std::istringstream iss(str);
        std::string id, brand, model, volume;
        int bodyType, transmission;
        double rate;
        bool hasCarSeat;
        char comma;

        iss >> id >> comma >> brand >> comma >> model >> comma >> volume >> comma >> bodyType >> comma
            >> transmission >> comma >> rate >> comma >> hasCarSeat;

        return Car(id, brand, model, volume, static_cast<BodyType>(bodyType), static_cast<Transmission>(transmission), hasCarSeat);
    }
}

void CarService::addCar(const Car& car) {
    cars.push_back(car);
}

void CarService::editCar(const std::string& carId, const Car& newCar) {
    auto it = std::find_if(cars.begin(), cars.end(), [&](const Car& car) {
        return car.getId() == carId;
    });
    if (it != cars.end()) {
        *it = newCar;
    }
}

void CarService::deleteCar(const std::string& carId) {
    cars.erase(std::remove_if(cars.begin(), cars.end(), [&](const Car& car) {
        return car.getId() == carId;
    }), cars.end());
}

void CarService::displayAllCars() const {
    std::cout << "List of all cars:\n";
    for (const auto& car : cars) {
        std::cout << "Car ID: " << car.getId() << ", Brand: " << car.getBrand() << ", Model: " << car.getModel() << '\n';
    }
}

Car* CarService::findCarById(const std::string& carId) {
    auto it = std::find_if(cars.begin(), cars.end(), [&](const Car& car) {
        return car.getId() == carId;
    });
    return it != cars.end() ? &(*it) : nullptr;
}

// Function to retrieve car data from a text file
void CarService::retrieveCarData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    cars.clear();

    std::string line;
    while (std::getline(file, line)) {
        cars.push_back(CarMapper::deserialize(line));
    }

    file.close();
}

void CarService::saveCarData(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing" << std::endl;
        return;
    }

    for (const auto& car : cars) {
        file << CarMapper::serialize(car) << '\n';
    }

    file.close();
}

std::vector<Car> CarService::findByBrand(const std::string& brand) const {
    std::vector<Car> result;
    for (const auto& car : cars) {
        if (car.getBrand() == brand) {
            result.push_back(car);
        }
    }
    return result;
}

std::vector<Car> CarService::findByModel(const std::string& model) const {
    std::vector<Car> result;
    for (const auto& car : cars) {
        if (car.getModel() == model) {
            result.push_back(car);
        }
    }
    return result;
}

std::vector<Car> CarService::findByVolume(const std::string& volume) const {
    std::vector<Car> result;
    for (const auto& car : cars) {
        if (car.getVolume() == volume) {
            result.push_back(car);
        }
    }
    return result;
}

std::vector<Car> CarService::searchByKeyword(const std::string& keyword) const {
    std::vector<Car> result;
    for (const auto& car : cars) {
        if (car.getId().find(keyword) != std::string::npos ||
            car.getBrand().find(keyword) != std::string::npos ||
            car.getModel().find(keyword) != std::string::npos ||
            car.getVolume().find(keyword) != std::string::npos) {
            result.push_back(car);
        }
    }
    return result;
}

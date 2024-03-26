#include "../Entities/car/Car.h"
#include <vector>
#include "sstream"
#include <fstream>
#include <iostream>

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

class CarService {
private:
    std::vector<Car> cars;

public:
    void addCar(const Car& car);

    void editCar(const std::string& carId, const Car& newCar);

    void deleteCar(const std::string& carId);

    void displayAllCars() const;

    Car* findCarById(const std::string& carId);

    void retrieveCarData(const std::string& filename);

    void saveCarData(const std::string& filename) const;

    std::vector<Car> findByBrand(const std::string& brand) const;

    std::vector<Car> findByModel(const std::string& model) const;

    std::vector<Car> findByVolume(const std::string& volume) const;

    std::vector<Car> searchByKeyword(const std::string& keyword) const;
};



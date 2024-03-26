#include "../../Entities/car/Car.h"
#include <vector>
#include "sstream"
#include <fstream>
#include <iostream>


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



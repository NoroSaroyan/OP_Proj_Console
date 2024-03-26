#include "Car.h"

#include <utility>

Car::Car(std::string id, std::string brand, std::string model, std::string volume, BodyType bodyType, Transmission transmission,
         bool hasCarSeat) : id(std::move(id)), brand(std::move(brand)), model(std::move(model)), volume(std::move(volume)), bodyType(bodyType), transmission(transmission),
                            hasCarSeat(hasCarSeat) {}

const std::string &Car::getBrand() const {
    return this->brand;
}


void Car::setBrand(const std::string &brand) {
    this->brand = brand;
}

const std::string &Car::getModel() const {
    return this->model;
}

void Car::setModel(const std::string &model) {
    this->model = model;
}

const std::string &Car::getVolume() const {
    return volume;
}

void Car::setVolume(const std::string &volume) {
    this->volume = volume;
}

BodyType Car::getBodyType() const {
    return this->bodyType;
}

void Car::setBodyType(BodyType bodyType) {
    this->bodyType = bodyType;
}

Transmission Car::getTransmission() const {
    return this->transmission;
}

void Car::setTransmission(Transmission transmission) {
    this->transmission = transmission;
}

bool Car::isHasCarSeat() const {
    return this->hasCarSeat;
}

void Car::setHasCarSeat(bool hasCarSeat) {
    this->hasCarSeat = hasCarSeat;
}

Car::Car() {}

const std::string &Car::getId() const {
    return id;
}

void Car::setId(const std::string &id) {
    Car::id = id;
}

double Car::getRate() const {
    return rate;
}

void Car::setRate(double rate) {
    Car::rate = rate;
}

Car::~Car() {
}

// пока не уверен, что нужен в такой реализации, но пусть будет
//ostream &operator<<(ostream &os, const Car &car) {
//    os << "brand: " << car.brand << " model: " << car.model << " volume: " << car.volume << " bodyType: "
//       << car.bodyType << " transmission: " << car.transmission << " hasCarSeat: " << car.hasCarSeat;
//    return os;
//}

//
// Created by Norik Saroyan on 26.03.24.
//

#include "Order.h"

#include <utility>

Order::Order() {}

Order::Order(std::string id, const std::chrono::time_point<std::chrono::system_clock> &startDate,
             const std::chrono::time_point<std::chrono::system_clock> &endDate, std::string carId, std::string clientId,
             double price) : id(std::move(id)), startDate(startDate), endDate(endDate), carId(std::move(carId)), clientId(std::move(clientId)),
                             price(price) {}

const std::string &Order::getId() const {
    return this->id;
}

void Order::setId(const std::string &id) {
    Order::id = id;
}

const std::chrono::time_point<std::chrono::system_clock> &Order::getStartDate() const {
    return startDate;
}

void Order::setStartDate(const std::chrono::time_point<std::chrono::system_clock> &startDate) {
    Order::startDate = startDate;
}

const std::chrono::time_point<std::chrono::system_clock> &Order::getEndDate() const {
    return endDate;
}

void Order::setEndDate(const std::chrono::time_point<std::chrono::system_clock> &endDate) {
    Order::endDate = endDate;
}

const std::string &Order::getCarId() const {
    return carId;
}

void Order::setCarId(const std::string &carId) {
    Order::carId = carId;
}

const std::string &Order::getClientId() const {
    return clientId;
}

void Order::setClientId(const std::string &clientId) {
    Order::clientId = clientId;
}

double Order::getPrice() const {
    return price;
}

void Order::setPrice(double price) {
    Order::price = price;
}


//
// Created by Norik Saroyan on 26.03.24.
//

#ifndef OP_PROJ_CONSOLE_ORDER_H
#define OP_PROJ_CONSOLE_ORDER_H


#include "string"
#include "../car/Car.h"
#include "ctime"
#include "chrono"
class Order {
private:
    std::string id;
    std::chrono::time_point<std::chrono::system_clock> startDate;
    std::chrono::time_point<std::chrono::system_clock> endDate;
    std::string carId;
    std::string clientId;
    double price;
public:
    Order(std::string id, const std::chrono::time_point<std::chrono::system_clock> &startDate,
          const std::chrono::time_point<std::chrono::system_clock> &endDate, std::string carId, std::string clientId,
          double price);

    Order();

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::chrono::time_point<std::chrono::system_clock> &getStartDate() const;

    void setStartDate(const std::chrono::time_point<std::chrono::system_clock> &startDate);

    const std::chrono::time_point<std::chrono::system_clock> &getEndDate() const;

    void setEndDate(const std::chrono::time_point<std::chrono::system_clock> &endDate);

    const std::string &getCarId() const;

    void setCarId(const std::string &carId);

    const std::string &getClientId() const;

    void setClientId(const std::string &clientId);

    double getPrice() const;

    void setPrice(double price);
};



#endif //OP_PROJ_CONSOLE_ORDER_H

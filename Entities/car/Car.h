#ifndef OP_PROJ_CONSOLE_CAR_H
#define OP_PROJ_CONSOLE_CAR_H


#include <ostream>
#include "string"
#include "BodyType.h"
#include "Transmission.h"
class Car {
private:
    std::string id;
    std::string brand;
    std::string model;
    std::string volume;
    BodyType bodyType;
    Transmission transmission;
    double rate;
public:
    double getRate() const;

    void setRate(double rate);

private:
    bool hasCarSeat;

public:
    Car(std::string id, std::string brand, std::string model, std::string volume, BodyType bodyType, Transmission transmission,
        bool hasCarSeat);

//    friend ostream &operator<<(ostream &os, const Car &car);

    Car();

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getBrand() const;

    void setBrand(const std::string &brand);

    const std::string &getModel() const;

    void setModel(const std::string &model);

    const std::string &getVolume() const;

    void setVolume(const std::string &volume);

    BodyType getBodyType() const;

    void setBodyType(BodyType bodyType);

    Transmission getTransmission() const;

    void setTransmission(Transmission transmission);

    bool isHasCarSeat() const;

    void setHasCarSeat(bool hasCarSeat);

    virtual ~Car();
};


#endif //OP_PROJ_CONSOLE_CAR_H

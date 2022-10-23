#ifndef SPEEDBOAT_H
#define SPEEDBOAT_H

#include "Ship.h"

class Speedboat : public Ship {
private:
    std::string purpose;
    std::string housingMaterial;
    std::string drivingQualities;
    double speed;
    int maxCountOfPeople;

public:
    Speedboat();

    Speedboat(const std::string &purpose, const std::string &housingMaterial,
              const std::string &drivingQualities, double speed, int countOfPeople);

    Speedboat(const Speedboat &speedboat2);

    ~Speedboat() override;

    Speedboat *clone() const override;

    void displayData() const override;

    void editData() override;

    friend std::istream &operator>>(std::istream &is, Speedboat &speedboat);

    void writeToFile(std::fstream &file) const override;

    void readFromFile(std::fstream &file) override;

    const std::string &getPurpose() const;

    void setPurpose(const std::string &purpose);

    const std::string &getHousingMaterial() const;

    void setHousingMaterial(const std::string &housingMaterial);

    const std::string &getDrivingQualities() const;

    void setDrivingQualities(const std::string &drivingQualities);

    double getSpeed() const;

    void setSpeed(double speed);

    int getCountOfPeople() const;

    void setCountOfPeople(int countOfPeople);
};


#endif //SPEEDBOAT_H
